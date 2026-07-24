import requests
import serial
import time
import datetime


ser = serial.Serial('COM10', 115200)

def find_sensor(data, target_id):
    if data['id'] == target_id:
        return data
    for child in data['Children']:
        result = find_sensor(child, target_id)
        if result:
            return result
    return None

while True:
    current_time = datetime.datetime.now()
    hour = current_time.hour
    minute = current_time.minute
    time_str = f"{hour:02d}:{minute:02d}"
    response = requests.get("http://localhost:8085/data.json")
    data = response.json()
    
    cpu_sensor = find_sensor(data, 57)
    gpu_sensor = find_sensor(data, 147)
    
    cpu_temp = cpu_sensor['RawValue'].replace(' °C', '')
    gpu_temp = gpu_sensor['RawValue'].replace(' °C', '')
    
    message = f"CPU:{cpu_temp},GPU:{gpu_temp},TIME:{time_str}"
    print(message)
    ser.write((message + "\n").encode())
    time.sleep(3)
