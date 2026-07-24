#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <GxEPD2_4C.h>
#include <GxEPD2_7C.h>
#include <Fonts/pixeldeb8pt7b.h>
#include <Fonts/pixeldeb__1_40pt7b.h>
#define CS_PIN (17)
#define BUSY_PIN (14)
#define RES_PIN (15)
#define DC_PIN (16)

int updatecount = 0;

uint16_t leftgraphx = 22;
uint16_t rightgraphx = 233;
uint16_t graphY = 20;
uint16_t graphH = 147;
uint16_t graphW = 147;
uint16_t newcputemp = 78;
uint16_t newgputemp = 59;
String newtime = "00:00";
String lastDisplayedTime = "";
int cpugrapharray[49] = {0};
int gpugrapharray[49] = {0};
uint16_t lastcputemp = 0;
uint16_t lastgputemp = 0;


GxEPD2_BW<GxEPD2_420_GDEY042T81, GxEPD2_420_GDEY042T81::HEIGHT> display(GxEPD2_420_GDEY042T81(CS_PIN, DC_PIN, RES_PIN, BUSY_PIN));
void setup() {
  
  //display.init(115200); // default 10ms reset pulse, e.g. for bare panels with DESPI-C02
  Serial.begin(115200);
  display.init(115200, true, 2, false); // USE THIS for Waveshare boards with "clever" reset circuit, 2ms reset pulse
  display.setFullWindow();
  display.setRotation(180);
  display.firstPage();
  do{
    display.fillScreen(GxEPD_WHITE);
  } while (display.nextPage());
  routineRefresh();
}


void basic_layout() {
    display.setTextColor(GxEPD_BLACK);
    display.fillRect(19, 20, 3, 150, GxEPD_BLACK);
    display.fillRect(230, 20, 3, 150, GxEPD_BLACK);
    display.fillRect(19, 167, 150, 3, GxEPD_BLACK);
    display.fillRect(230, 167, 150, 3, GxEPD_BLACK);
    display.setFont(&pixeldeb8pt7b);
    display.setCursor(44, 190);
    display.print("CPU:");
    display.setCursor(255, 190);
    display.print("GPU:");
    //after this there is code for bottom sections, for them to be stationary for now cuz I do not want to work on right now
}

void updatetime() {
  if (newtime == lastDisplayedTime) return;  // skip if unchanged!
  lastDisplayedTime = newtime;
  
  display.setPartialWindow(90, 220, 300, 80);
  display.firstPage();
  do {
    display.fillRect(90, 220, 300, 80, GxEPD_WHITE);
    display.setCursor(95, 280);
    display.setFont(&pixeldeb__1_40pt7b);
    display.print(newtime);
  } while (display.nextPage());
}

void updategputemp() {
  if (newgputemp == lastgputemp) return;
  lastgputemp = newgputemp;
  
  display.setPartialWindow(299, 180, 60, 14);
  display.firstPage();
  char gpu[10];
  sprintf(gpu, "%dC", newgputemp);
  do {
    display.fillRect(299, 180, 60, 14, GxEPD_WHITE);
    display.setCursor(299, 190);
    display.setFont(&pixeldeb8pt7b);
    display.print(gpu);
  } while (display.nextPage());
}



void updatecputemp() {
    if (newcputemp == lastcputemp) return;
    lastcputemp = newcputemp;
    display.setPartialWindow(89, 180, 60, 14);
    display.firstPage();
    char cpu[10];
    sprintf(cpu, "%dC", newcputemp);
    do {
      display.fillRect(89, 180, 60, 14, GxEPD_WHITE);
      display.setCursor(89, 190);
      display.setFont(&pixeldeb8pt7b);
      display.print(cpu);
    }
    while (display.nextPage());
}

void cpugraph() {
  display.setPartialWindow(24, 20, 147, 147);
  display.firstPage();
  for (int c = 0; c < 48; c++) {
    cpugrapharray[c] = cpugrapharray[c + 1];
  }
  cpugrapharray[48] = newcputemp;
  do{
    display.fillRect(24, 20, 147, 147, GxEPD_WHITE);
    for (int n = 0; n < 49; n++) {
    int cpudotX = 22 + 3 * n;
    int cpuY = cpugrapharray[n] * graphH / 98;
    int cpudotY = graphY + graphH - cpuY;
    display.fillRect(cpudotX, cpudotY, 3, 3, GxEPD_BLACK);
  }
  } while (display.nextPage());
}
void updatecpu() {
  updatecputemp();
  cpugraph();
}

void gpugraph() {
  display.setPartialWindow(233, 20, 147, 147);
  display.firstPage();
  for (int g = 0; g < 48; g++) {
    gpugrapharray[g] = gpugrapharray[g + 1];
  }
  gpugrapharray[48] = newgputemp;
  do{
    display.fillRect(233, 20, 147, 147, GxEPD_WHITE);
    for (int n = 0; n < 49; n++) {
    int gpudotX = 233 + 3 * n;
    int gpuY = gpugrapharray[n] * graphH / 98;
    int gpudotY = graphY + graphH - gpuY;
    display.fillRect(gpudotX, gpudotY, 3, 3, GxEPD_BLACK);
  }
  } while (display.nextPage());
}

void updategpu() {
  updategputemp();
  gpugraph();
}

void update() {
  updatecpu();
  updategpu();
  updatetime();
}

void routineRefresh() {
  display.setFullWindow();
  
  display.firstPage();
  do {
    display.fillScreen(GxEPD_BLACK);
  } while (display.nextPage());
  
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
  } while (display.nextPage());
  
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    basic_layout();
  } while (display.nextPage());
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    int commaindex = data.indexOf(',');
    newcputemp = data.substring(data.indexOf(':') + 1, commaindex).toInt();
    int secondcomma = data.lastIndexOf(',');
    newgputemp = data.substring(data.indexOf(':', commaindex) + 1, secondcomma).toInt();
    newtime = data.substring(data.indexOf(':', secondcomma) + 1);
    updatecount++;
    if (updatecount >= 700) {
      routineRefresh();
      updatecount = 0;
    }
    update();
  }

};

          // just some notes
    //display.drawRect(89, 180, 60, 14, GxEPD_BLACK); //for future me, to make this partial refresh coordinates
    //display.setCursor(89, 190);
    //display.print("50c");
    //display.drawRect(299, 180, 60, 14, GxEPD_BLACK); //second partial refresh window
    //display.drawRect(0, 200, 199, 99, GxEPD_BLACK); //Border of the left bottom section
    //display.drawRect(200, 200, 199, 99, GxEPD_BLACK); //Border of the right bottom section
    //display.drawRect(200,200, 199, 50, GxEPD_BLACK); //right bottom section divider
