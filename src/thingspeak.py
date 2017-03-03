#python 3 imports
import http.client, urllib.parse, serial  
 
ser = serial.Serial("/dev/ttyACM0", 9600, timeout=1)
 
ser.write(b'T'); 
temperature = int(ser.read(3))  #leggo la temperatura
ser.write(b'H'); 
humidity = int(ser.read(3))  #leggo l'umidità
ser.write(b'P'); 
pressure = int(ser.read(3))  #leggo la pressione
 
params = urllib.parse.urlencode({"field1": temperature, "field2": humidity, "field3": pressure, "key":"XXXXXXXXXXXXXXXX"})
headers = {"Content-typZZe": "application/x-www-form-urlencoded", "Accept": "text/plain"}
conn = http.client.HTTPConnection("api.thingspeak.com:80")

try:
  conn.request("POST", "/update", params, headers); response = conn.getresponse()
  if(response.status == 200): print("Data logged successfully"); conn.close()
except:
  print("Errore di connessione")
