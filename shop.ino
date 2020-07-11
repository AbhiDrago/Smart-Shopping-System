#include<SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
#include<LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int buzzer=10;
String A = "   ";

int Count = 0,price = 0,Tag1 =0,Tag2 =0,Tag3=0,Tag4=0,Tag5=0,Tag6=0,Tag7=0,Tag8=0, count1=4, mtag0=0,mtag1=0,mtag2=0,mem=0,balance=0;

String member[3]={"2100854C4BA3","21002BC4E32D","0800988E100E"};
int memberbalance[3]={1000,1500,2000};
String cardarray[8]={"2600A4712FDC","270055322C6C","270055A3E839","270055A25888","270055A22AFA","270055A09A48","270055327C3C","270055A06AB8"};
int pricetag[8]={100,400,200,300,150,250,100,300};
String memberphone[3]={"9176070912","9176070912","9176070912"};
String membername[3]={"ABHIJIT","ASHWARTH","VARUN"};
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Welcome!");
  pinMode(10,OUTPUT);
}
void loop() 
{
digitalWrite(10,LOW);  
if(Serial.available())

{
 
 A=Serial.readString();
 Serial.println(A);
 delay(1000);


if(A==member[0]&&mtag0==0)

{
  
lcd.clear();
lcd.setCursor(0,0);
lcd.print(membername[0]);
delay(500);
lcd.setCursor(8,0);
lcd.print("Rs");
lcd.print(memberbalance[0]);
delay(500);
lcd.setCursor(0,1);
lcd.print(memberphone[0]);
delay(500);
mem=0;
balance=memberbalance[mem];
mtag0=1;
mtag1=0;
mtag2=0;
A="1";
Count = 0;
price = 0;
Tag1 =0;
Tag2 =0;
Tag3=0;
Tag4=0;
Tag5=0;
Tag6=0;
Tag7=0;
Tag8=0;

}

else if(A==member[1]&&mtag1==0)

{

lcd.clear();
lcd.setCursor(0,0);
lcd.print(membername[1]);
delay(500);
lcd.setCursor(8,0);
lcd.print(" Rs");
lcd.print(memberbalance[1]);
delay(500);
lcd.setCursor(0,1);
lcd.print(memberphone[1]);
delay(500);
mem=1;
balance=memberbalance[mem];
mtag0=0;
mtag1=1;
mtag2=0;
A="1";
Count = 0;
price = 0;
Tag1 =0;
Tag2 =0;
Tag3=0;
Tag4=0;
Tag5=0;
Tag6=0;
Tag7=0;
Tag8=0;
}

else if(A==member[2]&&mtag2==0)

{

lcd.clear();
lcd.setCursor(0,0);
lcd.print(membername[2]);
delay(500);
lcd.setCursor(8,0);
lcd.print("Rs");
lcd.print(memberbalance[2]);
delay(500);
lcd.setCursor(0,1);
lcd.print(     memberphone[2]);
delay(500);
mem=2;
balance=memberbalance[mem];
mtag2=1;
mtag0=0;
mtag1=0;
A="1";
Count = 0;
price = 0;
Tag1 =0;
Tag2 =0;
Tag3=0;
Tag4=0;
Tag5=0;
Tag6=0;
Tag7=0;
Tag8=0;
}



if(A==cardarray[0]&&Tag1==0)

{

lcd.clear();
lcd.setCursor(0,0);
Count+=1;
price+=pricetag[0];
Tag1=1;
if(price>balance)
  { digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
    
    lcd.print("Low Balance");
    lcd.setCursor(0,1);
    Tag1=0;
    Count=Count-1;
    price=price-pricetag[0];
    lcd.print("Av. Bal: Rs");
    lcd.print(balance-price);
    
    }
else{lcd.print("OIL ADDED");
lcd.setCursor(0,1);
lcd.print("Tot:");
lcd.print(price);
lcd.print(" Count:");
lcd.print(Count);
}
}

else if(A==cardarray[0]&&Tag1==1)

{

lcd.clear();
lcd.setCursor(0,0);
lcd.print("OIL REMOVED");
Serial.println("OIL REMOVED");
Count-=1;
price-=pricetag[0];
Tag1=0;

}

if(A==cardarray[1]&&Tag2==0)

{

lcd.clear();
lcd.setCursor(0,0);
Count+=1;
price+=pricetag[1];
Tag2=1;
if(price>balance)
  { digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
    
    lcd.print("Low Balance");
    lcd.setCursor(0,1);
    Tag2=0;
    Count=Count-1;
    price=price-pricetag[1];
    lcd.print("Av. Bal: Rs");
    lcd.print(balance-price);
    }
else
{lcd.print("PEN ADDED");
lcd.setCursor(0,1);
lcd.print("Tot:");
lcd.print(price);
lcd.print(" Count:");
lcd.print(Count);
}
}

else if(A==cardarray[1]&&Tag2==1)

{

lcd.clear();
lcd.setCursor(0,0);
lcd.print("PEN REMOVED");
Serial.println("PEN REMOVED");
Count-=1;
price-=pricetag[1];
Tag2=0;

}


if(A==cardarray[2]&&Tag3==0)
{

lcd.clear();
lcd.setCursor(0,0);

Count+=1;
price+=pricetag[2];
Tag3=1;
if(price>balance)
  { digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
    
    lcd.print("Low Balance");
    lcd.setCursor(0,1);
    Tag3=0;
    Count=Count-1;
    price=price-pricetag[2];
    lcd.print("Av. Bal: Rs");
    lcd.print(balance-price);
    }
else
{
  lcd.print("BISCUIT ADDED");
  lcd.setCursor(0,1);
  lcd.print("Tot:");
lcd.print(price);
lcd.print(" Count:");
lcd.print(Count);
}
} 
else if(A==cardarray[2]&&Tag3==1)
{
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("BISCUIT REMOVED");
Serial.println("BISCUIT REMOVED");
Count-=1;
price-=pricetag[2];
Tag3=0;

}


if(A==cardarray[3]&&Tag4==0)
{
  lcd.clear();
lcd.setCursor(0,0);


Count+=1;
price+=pricetag[3];
Tag4=1;
if(price>balance)
  { digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
    
    lcd.print("Low Balance");
    lcd.setCursor(0,1);
    Tag4=0;
    Count=Count-1;
    price=price-pricetag[3];
    lcd.print("Av. Bal: Rs");
    lcd.print(balance-price);
    }
    else
    {
      lcd.print("BOOK ADDED");
      lcd.setCursor(0,1);
      lcd.print("Tot:");
lcd.print(price);
lcd.print(" Count:");
lcd.print(Count);
    }
} 
else if(A==cardarray[3]&&Tag4==1)
{
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("BOOK REMOVED");
Serial.println("BOOK REMOVED");
Count-=1;
price-=pricetag[3];
Tag4=0;

}


if(A==cardarray[4]&&Tag5==0)
{
  lcd.clear();
lcd.setCursor(0,0);

Count+=1;
price+=pricetag[4];
Tag5=1;
if(price>balance)
  { digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
    
    lcd.print("Low Balance");
    lcd.setCursor(0,1);
    Tag5=0;
    Count=Count-1;
    price=price-pricetag[4];
    lcd.print("Av. Bal: Rs");
    lcd.print(balance-price);
    }
    else
    {
      lcd.print("BOX ADDED");
      lcd.setCursor(0,1);
      lcd.print("Tot:");
lcd.print(price);
lcd.print(" Count:");
lcd.print(Count);

    }
} 
else if(A==cardarray[4]&&Tag5==1)
{
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("BOX REMOVED");
Serial.println("BOX REMOVED");
Count-=1;
price-=pricetag[4];
Tag5=0;

}

if(A==cardarray[5]&&Tag6==0)
{
lcd.clear();
lcd.setCursor(0,0);


Count+=1;
price+=pricetag[5];
Tag6=1;
if(price>balance)
  { digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
    
    lcd.print("Low Balance");
    lcd.setCursor(0,1);
    Tag6=0;
    Count=Count-1;
    price=price-pricetag[5];
    lcd.print("Av. Bal: Rs");
    lcd.print(balance-price);
    }
    else {
      lcd.print("BATTERY ADDED");
      lcd.setCursor(0,1);
      lcd.print("Tot:");
lcd.print(price);
lcd.print(" Count:");
lcd.print(Count);
    }
} 
else if(A==cardarray[5]&&Tag6==1)
{
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("BATTERY REMOVED");
Serial.println("BATTERY REMOVED");
Count-=1;
price-=pricetag[5];
Tag6=0;

}

if(A==cardarray[6]&&Tag7==0)
{
  lcd.clear();
lcd.setCursor(0,0);
Count+=1;
price+=pricetag[6];
Tag7=1;
if(price>balance)
  { digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
    
    lcd.print("Low Balance");
    lcd.setCursor(0,1);
    Tag7=0;
    Count=Count-1;
    price=price-pricetag[6];
    lcd.print("Av. Bal: Rs");
    lcd.print(balance-price);
    }
    else{
      lcd.print("KNIFE ADDED");
      lcd.setCursor(0,1);
      lcd.print("Tot:");
lcd.print(price);
lcd.print(" Count:");
lcd.print(Count);
    }
} 
else if(A==cardarray[6]&&Tag7==1)
{
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("KNIFE REMOVED");
Serial.println("KNIFE REMOVED");
Count-=1;
price-=pricetag[6];
Tag7=0;

}

if(A==cardarray[7]&&Tag8==0)
{
  lcd.clear();
lcd.setCursor(0,0);

Count+=1;
price+=pricetag[7];
Tag8=1;
if(price>balance)
  {
    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
    
    lcd.print("Low Balance");
    lcd.setCursor(0,1);
    Tag8=0;
    Count=Count-1;
    price=price-pricetag[7];
    lcd.print("Av. Bal: Rs");
    lcd.print(balance-price);
    }
    else{
      lcd.print("CHARGER ADDED");
      lcd.setCursor(0,1);
      lcd.print("Tot:");
lcd.print(price);
lcd.print(" Count:");
lcd.print(Count);
    }
} 
else if(A==cardarray[7]&&Tag8==1)
{
  lcd.clear();
lcd.setCursor(0,0);
lcd.print("CHARGER REMOVED");
Serial.println("CHARGER REMOVED");
Count-=1;
price-=pricetag[7];
Tag8=0;

}

if(A==member[0]&&mtag0==1)

{
  Serial.print("*");
Serial.println(membername[0]);
delay(500);
Serial.println(memberbalance[0]);
delay(500);
Serial.println(memberphone[0]);
delay(500);
Serial.print("#");

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Success");
delay(500);
lcd.setCursor(8,0);
lcd.print("Rs");
lcd.print(price);
delay(500);
lcd.setCursor(0,1);
lcd.print("Balance: ");
lcd.setCursor(10,1);
balance=balance-price;
lcd.print(balance);
delay(500);
memberbalance[0]=balance;
        mySerial.println("AT");
        delay(1000);
        mySerial.println("AT+CMGF=1");
        delay(1000);
        mySerial.println("AT+CMGS=\"9965573405\"\r\n");
        delay(1000);
        mySerial.println("Purchase Successful");
        mySerial.println("Number of Products Purchased:");
        mySerial.println(Count);
        mySerial.println("Total Price:");
        mySerial.println(price);
        mySerial.println("Available Balance:");
        mySerial.println(balance);
        mySerial.println((char)26);
        delay(1000);


        mySerial.println("AT");
        delay(1000);
        mySerial.println("AT+CMGF=1");
        delay(1000);
        mySerial.println("AT+CMGS=\"9840497697\"\r\n");
        delay(1000);
        mySerial.println("Purchase Successful");
        mySerial.println("Number of Products Purchased:");
        mySerial.println(Count);
        mySerial.println("Total Price:");
        mySerial.println(price);
        mySerial.println("Available Balance:");
        mySerial.println(balance);
        mySerial.println((char)26);
        delay(1000);

    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
    
Count = 0;
balance=0;
price = 0;
Tag1 =0;
Tag2 =0;
Tag3=0;
Tag4=0;
Tag5=0;
Tag6=0;
Tag7=0;
Tag8=0;
mtag0=0;
}

else if(A==member[1]&&mtag1==1)

{
Serial.print("*");
Serial.println(membername[1]);
delay(500);
Serial.println(memberbalance[1]);
delay(500);
Serial.println(memberphone[1]);
delay(500);
Serial.print("#");



lcd.clear();
lcd.setCursor(0,0);
lcd.print("Success");
delay(500);
lcd.setCursor(8,0);
lcd.print("Rs");
lcd.print(price);
delay(500);
lcd.setCursor(0,1);
lcd.print("Balance: ");
lcd.setCursor(10,1);
balance=balance-price;
lcd.print(          balance);
delay(500);
memberbalance[1]=balance;
        mySerial.println("AT");
        delay(1000);
        mySerial.println("AT+CMGF=1");
        delay(1000);
        mySerial.println("AT+CMGS=\"9965573405\"\r\n");
        delay(1000);
        mySerial.println("Purchase Successful");
        mySerial.println("Number of Products Purchased:");
        mySerial.println(Count);
        mySerial.println("Total Price:");
        mySerial.println(price);
        mySerial.println("Available Balance:");
        mySerial.println(balance);
        mySerial.println((char)26);
        delay(1000);


        mySerial.println("AT");
        delay(1000);
        mySerial.println("AT+CMGF=1");
        delay(1000);
        mySerial.println("AT+CMGS=\"9840497697\"\r\n");
        delay(1000);
        mySerial.println("Purchase Successful");
        mySerial.println("Number of Products Purchased:");
        mySerial.println(Count);
        mySerial.println("Total Price:");
        mySerial.println(price);
        mySerial.println("Available Balance:");
        mySerial.println(balance);
        mySerial.println((char)26);
        delay(1000);

    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);

Count = 0;
balance=0;
price = 0;
Tag1 =0;
Tag2 =0;
Tag3=0;
Tag4=0;
Tag5=0;
Tag6=0;
Tag7=0;
Tag8=0;
mtag1=0;    
}

else if(A==member[2]&&mtag2==1)

{
Serial.print("*");
Serial.println(membername[2]);
delay(500);
Serial.println(memberbalance[2]);
delay(500);
Serial.println(memberphone[2]);
delay(500);
Serial.print("#");

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Success");
delay(500);
lcd.setCursor(8,0);
lcd.print("Rs");
lcd.print(price);
delay(500);
lcd.setCursor(0,1);
lcd.print("Balance: ");
lcd.setCursor(10,1);
balance=balance-price;
lcd.print(balance);
delay(500);
memberbalance[2]=balance;

        mySerial.println("AT");
        delay(1000);
        mySerial.println("AT+CMGF=1");
        delay(1000);
        mySerial.println("AT+CMGS=\"9965573405\"\r\n");
        delay(1000);
        mySerial.println("Purchase Successful");
        mySerial.println("Number of Products Purchased:");
        mySerial.println(Count);
        mySerial.println("Total Price:");
        mySerial.println(price);
        mySerial.println("Available Balance:");
        mySerial.println(balance);
        mySerial.println((char)26);
        delay(1000);


        mySerial.println("AT");
        delay(1000);
        mySerial.println("AT+CMGF=1");
        delay(1000);
        mySerial.println("AT+CMGS=\"9840497697\"\r\n");
        delay(1000);
        mySerial.println("Purchase Successful");
        mySerial.println("Number of Products Purchased:");
        mySerial.println(Count);
        mySerial.println("Total Price:");
        mySerial.println(price);
        mySerial.println("Available Balance:");
        mySerial.println(balance);
        mySerial.println((char)26);
        delay(1000);

    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    delay(1000);
Count = 0;
balance=0;
price = 0;
Tag1 =0;
Tag2 =0;
Tag3=0;
Tag4=0;
Tag5=0;
Tag6=0;
Tag7=0;
Tag8=0;
mtag2=0;    
}


}


}
