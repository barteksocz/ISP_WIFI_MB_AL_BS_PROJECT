# Arduino + ESP8266 Sparkfun
![alt text](https://cdn.sparkfun.com/assets/learn_tutorials/4/0/3/angled.jpg)

Przykładowe zastosowanie modułu esp8266 sparkfun połączonego z arduino Uno. 

Zadaniem modułu jest komunikacja z zewnętrznym serwerem za pomocą protokołu HTTP.

Moduł posiada możliwość komunikacji jedynie za pomocą protokołu TCP. 
Wyższa warstwa komunikacji (ramka HTTP) składana jest bezpośrednio w kodzie programu.

Obsługa modułu esp8266 przeprowadzona jest za pomocą biblioteki udostępnionej przez firme SparkFun. 
Zaleca się nie stosowanie użytej biblioteki w przyszłych aplikacjach. 
Kod zastosowanej biblioteki jest słabo zoptymalizowany - posiada błędy w implementacji komend AT. 
Dodatkowo w specyficznych sytuacjach może dojść do wycieku pamięci.  

### Krok I
Ustaw nazwe SSID oraz hasło sieci WIFI z która nastąpi połączenie. Dodatkowo należy ustawić adres serwera dostępnego w sieci oraz jego port.

```
const char wifi_SSID[] = "UPC1131478";
const char wifi_PSW[] = "UERGPQCM";

const char server_address[] = "192.168.0.19";
const int server_port = 99;
```

```
const String httpRequest = "POST /sensors_data HTTP/1.1\r\n"
                           "Host: 192.168.0.19:99\r\n"
                           "Content-Type: application/x-www-form-urlencoded\r\n" 
                           "Connection: close\r\n"
                           "content-length: ";                       
```                          

### Krok II
Komunikacja z płytką arduino domyślnie wymienia informacje za pomocą protokołu USART zorganizowanego programowo. 
Należy zwrócić uwagę na poprawne położenie dostępnego przełącznika.

Powyższy kod poprawnie działa na najnowszej wersji firmware modułu wifi-shield. 
Przed zastosowaniem warto zaktualizować wersję do tej najnowszej. 
Więcej informacji na temat aktualizacji można znaleźć na stronie http://moduliki.pl/archiwa/798

### Krok III
Zapewnij stabilne źródło zasialania płytki Arduino oraz modułu esp8266. 
Losowy reset modułu w większości przypadku jest spowodowany zbyt małą wydajnością źródła zasilania 
(zasilanie modułu esp8266 powinno pochodzić z zewnętrznego zasilacza)!
