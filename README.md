## Więcej o typach zmiennych i nie tylko
### **Zasięg zmiennej**
W języku C istnieją dwa rodzaje zasięgów zmiennych. Zmienna globalna i zmienna lokalna. We wszystkich przykładach użytych wcześniej, spotkaliśmy się z deklaracją zmiennych lokalnych, gdyż bardzo rzadko używa się zmiennych globalnych. Zmienną globalną zazwyczaj deklaruje się poniżej dyrektywy preprocesora (#include <…>). Jest ona wtedy dostępna w całym kodzie i dla każdej funkcji (o funkcjach mowa w kolejnym rozdziale). Jednak każdy kod da się zapisać bez używania zmiennych globalnych i zazwyczaj unika się jednak ich używania (chociaż czasem są bardzo przydatne). Drugą kwestią są zmienne lokalne. Zmienna lokalna to taka zmienna, do której mamy dostęp tylko w bloku kodu, w którym została zadeklarowana. Blok kodu to kod zawarty pomiędzy nawiasami klamrowymi np. w funkcjach, pętli for, czy instrukcji warunkowej. Do takiej zmiennej nie uda nam się odwołać po zakończeniu tego bloku. 

*Przykład (6.0) zasięg zmiennej*
```
#include <stdio.h>
#include <stdlib.h>
int zmienna_globalna=0;
int main() {
	int zmienna_lokalna_main=1;
	
	if(zmienna_lokalna_main==1)
	{
		int zmienna_lokalna_if=2;
 		printf("%d ",zmienna_globalna); /* dostęp OK */
 		printf("%d ",zmienna_lokalna_main); /* dostęp OK */
 		printf("%d ",zmienna_lokalna_if); /* dostęp OK */
	}
}
```
```
 /* ---------------- teraz kod z błędem ---------------------- */
#include <stdio.h>
#include <stdlib.h>
int zmienna_globalna=0;
int main() {
	int zmienna_lokalna_main=1;
	
	if(zmienna_lokalna_main==1)
	{
		int zmienna_lokalna_if=2;
	} /* poza tym nawiasem klamrowym już zmienna_lokalna_if nie jest już widoczna*/
printf("%d ",zmienna_globalna); /* dostęp OK */
 		printf("%d ",zmienna_lokalna_main); /* dostęp OK */
 		printf("%d ",zmienna_lokalna_if); /* BŁĄD !!!*/

}

```

W zmiennych lokalnych istotnym elementem jest przysłanianie zmiennych. Jest to zadeklarowanie zmiennej o tej samej nazwie w innym bloku kodu. Zmienna taka przysłoni zmienną z bloku zewnętrznego, czyli wewnątrz tego bloku stracimy do niej dostęp. Zmienna lokalna może też przysłonić zmienną globalną.

*Przykład (6.1) przysłonięcie zmiennej*
```
#include <stdio.h>
#include <stdlib.h>
int zmienna_globalna=0;
int main() {
	int zmienna_lokalna=1;
	
	if(zmienna_lokalna==1)
	{
		int zmienna_lokalna=2; /* przysłania zmienną z main */
 		printf("%d ",zmienna_globalna);
 		printf("%d \n",zmienna_lokalna);
	}
	printf("%d ",zmienna_globalna);
 	printf("%d ",zmienna_lokalna);
}

```

*Wynik działania programu*

>0 2
>
>0 1

### **Modyfikatory typów zmiennych oraz stałe**
Modyfikatory typów dają nam większą kontrolę nad rozmiarem pamięci zajmowanym przez zmienną oraz, typem przechowywania wartości. W języku C występują 4 modyfikatory:

- short - krótka
- long - długa
- signed – ze znakiem (+ lub -)
- unsigned – bez znaku (tylko +)

Dwa pierwsze (short i long) odpowiadają za rozmiar pamięci zajmowany przez zmienną, i można ich używać ze wszystkimi podstawowymi zmiennymi. Kolejne dwa (signed i unsigned) są odpowiedzialne za typ zapisu danych. W ten sposób zmodyfikujemy zbiór wartości do jakiego może należeć zmienna. Modyfikatorów signed i unsigned nie można używać z typem zmiennej zmiennoprzecinkowej (float i double). Każdy z modyfikatorów można użyć samodzielnie – bez deklarowania typu zmiennej. Tak zadeklarowana zmienna, stanie się domyślnie zmienną całkowitą (zapis  short digit  i short int digit są równoznaczne).  

|Typ|Liczba bitów N|Zakres wartości : -2N-1… 2N-1-1|Kod formatujący|
| - | - | - | - |
|`char`|8 |-128 … 127|%c|
|`short`|16|-32 768 … 32 767|%hd |
|`int` |16|-32 768 … 32 767|%d|
|`int` |32|-2 147 483 648 … 2 147 483 647|%d|
|`long`|32|-2 147 483 648 … 2 147 483 647|%ld |
|`long long`|64|−9 223 372 036 854 775 808 …9 223 372 036 854 775 807|%lld |
|`unsigned char`|8|0 … 255|%c|
|`unsigned short`|16|0 … 65 535|%hu |
|`unsigned` (`unsigned int`)|16|0 … 65 535|%u |
|`unsigned` (`unsigned int`)|32|0 … 4294 967 295|%u|
|`unsigned long`|32|0 … 4294 967 295|%ul |

W zależności od systemu zapisu plików komputera i kompilatora, rozmiar oraz wartości min i max przedziałów zmiennych typu `int` oraz `unsigned`. 
Zmienna typu `long long` istnieje tylko w nowych kompilatorach.

|Typ|Liczba bitów|Liczba cyfr znaczących|Zakres wartości  |Kod formatujący|
| - | - | - | - | - |
|`float` |32|7|3.4 ∙10-38… 3.4 ∙1038|` `%f|
|`double`|64|15|1.7 ∙10-308…1.7 ∙10308|%lf|
|`long double`|80|19|3.4 ∙10-4932… 1.1 ∙104932|%Lf|

Zmienna stała jest zmienną, której wartość nie może ulec zmianie. Jest to przydatne w momentach gdy kiedy chcemy mieć pewność, że żadne działanie nie zmodyfikuje nam wartości zmiennej. Aby stworzyć zmienną stałą należy użyć słowa kluczowego const przed typem (modyfikatorem) zmiennej.

*Przykład (6.2) Deklaracja stałej*
```
const flaot PI=3.14159265359;
/* mamy pewność że zmiennej PI nic nie zmodyfikuje – unikniemy błędów w obliczeniach*/
```

W języku C można też stworzyć *stałą symboliczną*. Do tego używa się dyrektywy preprocesora #define. Definicja takiej stałej symbolicznej różni się od zmiennej. Zmienna jest zapisywana do pamięci, natomiast stała symboliczna, jest wykrywana przez kompilator w chwili kompilacji zastąpi nazwę ciągiem znaków. W przykładzie 6.3, wpisując w dowolnym miejscu w kodzie `ARRAY_SIZE` kompilator potraktuje jakby było wpisane 6.

*Przykład (6.3) Deklaracja stałej symbolicznej*

`#define ARRAY_SIZE 6`

Poniżej zaimplementowany jest przykład w formie żartu, co można zrobić ze stałą symboliczną. Program działa, ale nie polecam programować w ten sposób programować.

*Przykład (6.4) Nadużycie stałych symbolicznych*
```
#include <stdio.h>
#include <stdlib.h>
#define e int
#define ee main
#define eee (
#define eeee )
#define eeeee {
#define eeeeee printf
#define eeeeeeeeee \n
#define eeeeeeeeeee ;
#define eeeeeeeeeeee return
#define eeeeeeeeeeeee 0
#define eeeeeeeeeeeeee }

e ee eee eeee
eeeee
	eeeeee eee "Hello World!\n" eeee eeeeeeeeeee
	eeeeeeeeeeee eeeeeeeeeeeee  eeeeeeeeeee
eeeeeeeeeeeeee

```
*Wynik działania programu*

>Hello World!

***
[Poprzednia część](https://github.com/CyberMALab/Petle.git) | [Spis treści](https://github.com/CyberMALab/Wprowadzenie-do-programowania-w-j-zyku-ANSI-C.git) | [Następna część](https://github.com/CyberMALab/Comming-Soon.git)
***
&copy; Cyberspace Modelling and Analysis Laboratory
