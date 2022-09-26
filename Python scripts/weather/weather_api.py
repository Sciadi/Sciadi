import requests

API_KEY = 'd3cf326fe7710347b8a0ea7b0c7964f1'
BASE_URL = 'http://api.openweathermap.org/data/2.5/weather'

KELVIN_CONSTANT = -273, 15


def print_weather_info(weather):
    main = weather['desc'][0]['main']
    main_desc = weather['desc'][0]['description']
    temp = float(weather['info']['temp']) - KELVIN_CONSTANT
    temp_real = float(['info']['feels_like']) - KELVIN_CONSTANT

    print(f"Weather: {main}, {main_desc}")
    print(type(weather['info']))
    print(f"Temperature (°C): {temp} feels like {temp_real}")


city = input("City:\t")
# appid and q are query parameters
request_url = f'{BASE_URL}?appid={API_KEY}&q={city}'
response = requests.get(request_url)

if response.status_code == 200:
    data = response.json()
    weather_info = {
        'desc': data['weather'],
        'info': data['main']
    }
    # print(data)
    print_weather_info(weather_info)
else:
    print("An error occured")
