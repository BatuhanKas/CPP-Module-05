
# CPP-Module-05

Bu projenin amaci size Try-Catch mekanizmasinin nasil calistigini ogretmektir.

***Projede başlamadan önce;*** Ilk once Try-catch'in nasil calistigini ogrenelim. Daha sonra egzersizlere geceriz.
Cunku bize yaptirdigi egzersizler zor degil, sadece ugrastirici. Sana katacagi tek sey Try Catch'in nasil calistigini ogrenmek.

Ben burada kisa bir sekilde anlatacagim fakat [notion](https://alike-dirigible-d37.notion.site/CPP-Notlarim-86e5660b50d740b5bd6b8803c8ae99f0#e48a300c4e0c44008c30dc95ed1b14c0) hesabimda'da try-catch kullanimi detayli bir sekilde anlattim. Istersen oradan da bakabilirsin.

-   Try Catch’in mantigi aslinda basittir. C’de malloc ile heap’te yer acildiktan sonra nasil acilip acilmadigini kontrol ediyorsak, burada try, catch bu islemi bizim icin kendisi yapiyor.
-   Biz bu kontrol islemini **TRY** blogu icerisinde yapiyoruz. Herhangi bir hata olusmasi durumunda bu hata, **CATCH** kismina dusuyor. Catch blogu hatayi yakaladigi icin, biz bu kisimda hatanin ne olduguna bakiyoruz.
-   Bu hatalar sadece **NEW** ile sinirli degildir. **EXCEPTION** adinda bir hata sinifimiz var, bu sinifimizin altinda bir suru hata bloklari vardir. Biz bu hata bloklarindan istediklerimizi kullanabiliriz.
-   Try-Catch bloklari programimizda hata durumlarini duzgun bir sekilde yonetmemizi saglar.

**Try:** İçinde bir istisna yaratacak, hata oluşabilecek kodu yazdığınız bloktur. Eğer bu blok içinde bir hata oluşursa, bu hata yakalanır ve **catch** bloğuna yönlendirilir.

**Throw:** Bir istisna (exception) fırlatmak için kullanılır. Programda bir hata veya beklenmedik durum oluştuğunda, bu durumu belirtmek ve yakalamak için kullanılır.

**Catch:** Bir istisna firlatildigi zaman, firlatilan hata Catch bloguna duser. Bu blokta hatanin ne hatasi oldugunu ogreniriz.


## Exception Class’i ve Alt Siniflari

![](https://i.hizliresim.com/d3fx7wv.jpeg)

### Runtime Error
-   Çalışma zamanı (runtime) sırasında ortaya çıkan hataları belirtmek için kullanılır. Bu tür hatalar, program çalışırken beklenmedik durumlar oluştuğunda meydana gelir.
-   Bellek yetersizliği, dosya okuma/yazma hataları, sıfıra bölme gibi durumlarda runtime_error kullanırız.

### Logic Error
-   Programın mantıksal hatalarını belirtmek için kullanılır. Bu hatalar, programın mantığında yapılan yanlışlıklardan kaynaklanır ve genellikle programlama hataları olarak değerlendirilir.
-   Geçersiz bir argümanın bir fonksiyona iletilmesi, bir dizinin sınırları dışında erişim yapılması gibi durumlarda logic error kullaniriz.

### Bad Alloc
-   Dinamik bellek ayırma işlemi (örneğin `new` operatörü ile) başarısız olduğunda atılan bir istisnadır. Bu durum genellikle heap'te yeterli bellek olmadığında meydana gelir.

<br>
Genelde kullanirken yukaridaki 3 hata sinifini kullanacagiz. Bu yuzden bu 3 tanesini ele alip anlatmak istedim. Birde direkt olarak Exception Class'ini ele alarak yapabiliriz.

<br>
Daha iyi anlasilmasi icin asagiya bir ornek veriyorum;

```c++
#include  <iostream> 
using  namespace  std;

void  checknum(int num) throw(runtime_error,  logic_error) {
	if (num ==  0) {
		throw  runtime_error("num can't be zero");
	}  else  if (num <  0) {
		throw  logic_error("num can't be lower than zero");
	}  else  {
		cout <<  "num: "  << num << endl;
	}
}

int  main() {
	try  {
		checknum(-7);
		checknum(10);
	}  catch (logic_error &le) {
		cerr <<  "logic_error: "  <<  le.what() << endl;
	}  catch (runtime_error &re) {
		cerr <<  "runtime_error: "  <<  re.what() << endl;
	}
	/*
		Some other Codes...
	*/
}
```

Yukaridaki ornekte checknum adinda bir fonksiyon yazdim. Bu fonksiyon belirli hata kontrolleri yapiyor ve herhangi bir kosul uyusmadigi zaman bir hata donduruyor. 

Try Catch bloğu hangi satırda hata fırlatırsa ornegin ilk basta checknum adli fonksiyona -7 degerini yolluyorum. -7 degeri bana logic_error donduruyor. Error dondugu icin catch blogu error'u yakalayip ekrana hata bastiriyor. Bu raddeden sonra try blogunun icerisinde olan kodun devami calismayacak. checknum fonksiyona -7 degerini yolladim ve hata elde ettim, devaminde 10 degerini yollamayacaktir. Ayriyetten catch blogunun altinda baska kodlar olsaydi, main fonksiyonun devami olsaydi, devami calismaya devam edecekti.

Yukarida ben gordugunuz uzere, fonksiyonun yanina throw() parantezi acip, icerisine firlatmak istedigim nesne turlerini belirttim. Eger throw() acip icerisine herhangi bir sey yazmasaydim, bir exception firlatmayacagimi soylemis olurdum. Ancak ben hata firlatip, throw() acip icini bos biraksaydim buyuk ihtimal abort yerdim. cunku exception firlatiyorum fakat yukarida parantez icerisinde belirtmiyorum. Bu kullanimin soyle sorun cikartan bir durumu var. Eger ben fonksiyonun yanina hic throw yazmasaydim, bu fonksiyon yine calisacakti.

```jsx
void checknum(int num)
```

Yani yukaridaki gibi bir tanim yapsam ve icerisinde throw firlatsam, ancak fonksiyonun yanindaki throw olmasa yine calisacakti. Yukarida throw parantezi olan kullanim eskiden dogru bir kullanimdi. Fakat C++ authorlari bu syntax’i C++11’de onermemeye baslamislar, C++17’de ise komple kullanimdan kaldirmislar. throw yerine noexcept diye bir syntax getirmisler. Bu yuzden artik c++ dili fonksiyonun yanina throw() parantezi ile belirtmesen dahi, catch blogu kendisi yakalayabiliyor.

noexcept ile fazla bilgi istersen eger default degeri ise true oluyor. noexcept(true) yani adi ustunde noexception, hata dondurmeyecek demek. Fakat degerini false yaparsak noexcept(false) o halde hata dondurecegini belirtiyoruz. Fakat bu kullanim bizde suan yasak. Biz eski usul throw catch kullanacagiz.

Throw ile firlattigim nesneleri customize edebilirim. Ben C++05 projesinde kendi error’umu yazmistim diye hatirliyorum. Yani throw atarken illaha exception classlarindan birini return edecegiz diye bir kaide yok. Kendi hata sinifimizi yazip, kendi hata objemizi return edebiliriz. Bu projede bunu yapacagiz.

Hatalarimizi kendimiz kisisellestirip mantikli bir sekilde kullanabiliriz.


### what() fonksiyonu

Tanimi asagidaki sekilde oldugu gibidir.
|virtual const char* what() const throw();|
|-----------------------------------------|

- Exception nesnesinin hata mesajını döndürmek için kullanılır. Bu fonksiyon, istisnanın nedenini veya türünü açıklayan char* dizisi döner.
<br>

####  **Proje Hakkinda** 
Projede kendi olusturdugumuz hata siniflari orthodox canonical form'a uygun olmak zorunda degil haberiniz olsun. Zaten bunu pdf'tede belirtmis + main kisimda hata sinifindan obje olusturup islem yapamiyoruz. Cunku adi ustunde hata sinifi sadece hatalarda kullanacagiz.

## **Ex00**

 - Bu kisimda bir Burokrat sinifi olusturacagiz. En yuksek Seviye 1, En dusuk seviye 150 olacak.
  - Bizden kendi hata sinifimizi olusturmamiz isteniyor. Çok düşükk seviyeli bir burokrat olusturursak ya da çok yüksek seviyeli bir bürokrat olusturursak bize hata dondurmesi gerekiyor.
  - Ayriyetten bir burokratin seviyesini arttiracak increase, decrease fonksiyonlarini yazmamiz gerekiyor. Seviyesi 1 olan bir burokratin seviyesini arttirmaya calistirinca hata dondurmesi gerekiyor.
- Pdf'in bizden istediklerini yazin ekstra bir sey yok.
- Ben burada ekstra olarak Hata yakalamayi iyice pekistirebilmek icin kendi error'umu yazmistim. main'de kendi error objemi yakaliyorum, exception ya da alt class'larini degil. 

## **Ex01**

- Burada bir Form sinifi olusturacagiz, icerisinde yine kendi hata siniflari olacak.
- Formun **ismi**, **seviyesi**, **signGrade** ve **executeGrade'i** olacak.
- **beSigned** isminde formun imzalanmasi icin gereken sartlari kontrol eden bir fonksiyon olacak. Gerekli sartlar kontrol edildikten sonra formu imzalayacak.

Bir kac hata durumundan bahsetmek gerekirse, bi burokratim var seviyesi 10. (Yuksek) Bir form var ve formun imzalanma Seviyesi(signGrade) ise 50. Benim seviyem yettigi icin ben bu formu imzalayabilirim. Ancak seviyem yetmezse ben burada bir hata mesaji bastirip ardindan exception dondurmek zorundayim. Burada 2 adet imzalama fonksiyonu vardi biri beSigned digeri ise signForm olmasi lazim. imzalamak icin burokratin signForm fonksiyonunu kullaniyoruz. Zaten signForm kendi icerisinde beSigned fonksiyonunu cagiriyor cunku zaten gerekli kontrolleri o form'un icerisinde yapmistik. Bir daha ayni seyi 2 kez yapmaya gerek yok.

Form imzalanmasi icin seviyesini kontrol etmen gerekiyor. Ettikten sonra formun durumunu imzalandi diye guncellemen gerekiyor. operator << 'u ise tekrardan yazip bilgileri goruntuleyebilmen gerekiyor. 

## **Ex02**

Bu kisimda isler karisiyor iste arkadaslar sıkı durun.
- Bu kisimda Ex01'de olusturdugumuz Form objesini **Abstract(Soyut)** hale getirmemiz gerekiyor. Cunku artik Formlarimizin isimleri olacak ve 3 farkli formumuz olacak.
- Form sinifimizi kullandigimiz her yeri **AForm** olarak degistirmemiz gerekecek.
- Parametre olarak bir adet burokrat alan bir **execute** fonksiyonu yazmamiz isteniyor. Bu fonksiyonu AForm class'ini soyut yapmak icin kullanabiliriz.

Bu satirdan itibaren asagida verdigim Formlari calistirmak icin bir burokrat tanimladigimi ve en yuksek seviyede oldugunu farzedin. Butun formlari duzgun bir sekilde calistirdigini varsayiyorum. Hata durumlarini daha sonra ele alacagim.

Bu formlar icin somut olmasi gerektigini soylemis. Asil ana AForm classimizi bu siniflara miras aldirip, execute fonksiyonlarini yazmamiz gerekiyor.

Bu formlar parametre olarak bir **TARGET** aliyor. 
Soldan Saga (signGrade, executeGrade)

***Shrubbery Creation Form (145, 137)***
 - Bu Form'u imzalamak icin min 145, calistirmak icin min 137 seviyeye sahip olmak gerekiyor. 
 - Bu formu imzalayip, calistirdiktan sonra "targetName" + "_shruberry" ekleyerek bir dosya olusturup icerisinde bir ASCII art olarak ağaç çizmesi gerekiyor. (ofstream serbest, trunc flagini kullanmayi unutmayin)

***Robotomy Request Form (72, 45)***
 - Bu Form'u imzalamak icin min 72, calistirmak icin min 45 seviyeye sahip olmak gerekiyor. 
 - Bu formu imzalayip, calistirdiktan sonra %50 ihtimalle target'i Robotlastirabiliyor ya da basarisiz oluyor. Bunu robot ureten bir makina olarak dusunebilirsiniz. Target ise hedefi. F16 verdim %50 ihtimalle ya F16 yapti ya da basarisiz oldu. (srand serbest)

***Presidential Pardon Form (25, 5)***
 - Bu Form'u imzalamak icin min 25, calistirmak icin min 5 seviyeye sahip olmak gerekiyor. 
 - Bu formu imzalayip, calistirdiktan sonra ekrana Zaphod Beeblebrox pardon yazısı bastırıyor. Bu yazinin dogrusu pdf'te var oradan kopyalayabilirsiniz.

####  Buradaki asıl kontrol edilmesi gereken şey ise şu. Ben bu formlari imzalamadan çalıştırmaya çalışırsam eğer, form imzalanmadı diye exception döndürmem gerekiyor. Diger kontroller ayni seviyelerini kontrol edeceksin yetecekse imzalayacak.

Çalıştırma sırasında ise bürokratın executeForm ismindeki fonksiyonuna gönderecek. Formların hepsi birbiri ile aynı. Sadece çalıştırma fonksiyonları ve yaptığı işlevler değişiyor. Birini yazdıktan sonra diğerleri çorap söküğü gibi gelecek.

## **Ex03**

- Bu kisimda bir stajyer(KÖLE) sınıfı tasarlayacağız. Stajyere istediğimiz formun ismini vereceğiz ve bize stajyerimiz istediğimiz formu heap'te açacak ve bize return edecek. Tüm yapmamız gereken şey bu. Tek dikkat etmemiz gereken şey ise **if/else if/else kullanimi yasak**. if else kullanmadan bu egzersizi yapmamiz gerekiyor. 

 - Ben kendim ekstra olarak burada olmayan bir form'u olusturmaya calistigim zaman(cunku 3 adet olusturabildigim form var ben gidip arabaForm diye bir sey gonderirsem exception firlatsin diye yazdim) hata firlatmasi icin bir hata sinifi yazdim. Bu sizin keyfinize kalmis nasil isterseniz oyle yapin.

- Stajyerin makeForm diye bir fonksiyonu olacak onu yazacaksiniz. 2 parametre alacak biri **olusacak olan form ismi**, digeri ise **target** olacak.

- Gonderdiginiz isimdeki formu target ile olusturacak ve return edeceksiniz. Bunu bir benzerini zaten CPP01 in yanlis hatirlamiyorsam son ex'inde pointer to member functionlar ile yapmistik. Fakat burada ona da gerek yok daha kolay. Çok kolay bir şekilde yapabileceğinizi düşünüyorum. 

- Projede new kullandığınız için leak'lerinizi kontrol etmeyi unutmayın! Projede leak olmaması gerekiyor.

Projenin gereksinimleri bunlardı. Eğer eksiklerimi görürseniz projeye issue açıp eksiklerimi belirtirseniz fixleyip repoyu güncelleyebilirim.

Projenin başındada belirttiğim gibi [notion](https://alike-dirigible-d37.notion.site/CPP-Notlarim-86e5660b50d740b5bd6b8803c8ae99f0#e48a300c4e0c44008c30dc95ed1b14c0) notlarıma buradan ulaşabilirsiniz. Hepinize başarılar diliyorum.
