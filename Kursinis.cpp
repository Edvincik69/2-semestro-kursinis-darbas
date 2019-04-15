#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <vector>
using namespace std;

class bazine
{
  protected:
  int x, y, a, b, ilgis, kryptis, raides, skaiciai;
  string ivesta_pozicija, ivesta_kryptis, ejimas, sudetis;
  string zaidejo_lentele[11][11];
  string kompiuterio_lentele[11][11];
  string zaidejo_spejimai[11][11];
  vector<int> zaid_laivai;
  vector<int> komp_laivai;

  public:
  bazine():raides(0), skaiciai(0){}
  bazine(int a, int b): raides(a), skaiciai(b){}
  bazine(const bazine&);
  ~bazine(){}

  void lenteliu_kurimas()
  {
    string x_atributai[10]={"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    string y_atributai[10]={"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    zaidejo_lentele[0][0]="";
    kompiuterio_lentele[0][0]="";
    zaidejo_spejimai[0][0]="";
    for(int i=0; i<11; i++)
    for(int j=0; j<11; j++)
    if(i>0||j>0)
    {
      if(i==0&&j>0)
      {
        zaidejo_lentele[i][j]=x_atributai[raides];
        kompiuterio_lentele[i][j]=x_atributai[raides];
        zaidejo_spejimai[i][j]=x_atributai[raides];
        raides++;
      }
      else if(i>0&&j==0)
      {
        zaidejo_lentele[i][j]=y_atributai[skaiciai];
        kompiuterio_lentele[i][j]=y_atributai[skaiciai];
        zaidejo_spejimai[i][j]=y_atributai[skaiciai];
        skaiciai++;
      }
      else
      {
        zaidejo_lentele[i][j]="☐";
        kompiuterio_lentele[i][j]="☐";
        zaidejo_spejimai[i][j]="☐";
      }
    }
    zaid_laivai.clear();
    zaid_laivai.push_back(2);
    zaid_laivai.push_back(3);
    zaid_laivai.push_back(3);
    zaid_laivai.push_back(4);
    zaid_laivai.push_back(5);
    komp_laivai.clear();
    komp_laivai=zaid_laivai;
  }

  virtual bool ivedimo_tikrinimas(string duota_pozicija)
  {
    duota_pozicija[0]=toupper(duota_pozicija[0]);
    if(duota_pozicija.size()==2)
    {
      if(isalpha(duota_pozicija[0]))
      {
        for(char i='A'; i<='J'; i++)
        if(duota_pozicija[0]==i&&isdigit(duota_pozicija[1])&&duota_pozicija[1]!='0') return true;
      }
    }
    if(duota_pozicija.size()==3)
    {
      if(isalpha(duota_pozicija[0]))
      {
        for(char i='A'; i<='J'; i++)
        if(duota_pozicija[0]==i&&duota_pozicija[1]=='1'&&duota_pozicija[2]=='0') return true;
      }
    }
    return false;
  }

  virtual bool koordinates_tikrinimas(int duotas_x, int duotas_y, string duota_lentele[][11])
  {
    if(duotas_x>10||duotas_y>10||duotas_x<1||duotas_y<1) return false;
    if(duota_lentele[duotas_x][duotas_y]=="■"||duota_lentele[duotas_x][duotas_y]=="·") return false;
    return true;
  }

  bool pozicijos_galimumas(int duotas_x, int duotas_y, int duotas_ilgis, string duota_kryptis, string duota_lentele[][11])
  {
    if(duota_kryptis=="1")
    {
      if(duotas_x-(duotas_ilgis-1)<1) return false;
      for(int i=0; i<duotas_ilgis; i++)
      if(duota_lentele[duotas_x-i][duotas_y]=="■"||duota_lentele[duotas_x-i][duotas_y]=="·") return false;
      for(int j=0; j<duotas_ilgis; j++)
      {
        duota_lentele[duotas_x-j][duotas_y]="■";
        if(y+1!=11) duota_lentele[duotas_x-j][duotas_y+1]="·";
        if(y-1!=0) duota_lentele[duotas_x-j][duotas_y-1]="·";
        if(duotas_x-j-1!=0&&j==duotas_ilgis-1)
        {
          duota_lentele[duotas_x-j-1][duotas_y]="·";
          if(duotas_y+1!=11) duota_lentele[duotas_x-j-1][duotas_y+1]="·";
          if(duotas_y-1!=0) duota_lentele[duotas_x-j-1][duotas_y-1]="·";
        }
        if(duotas_x+1!=11&&j==0)
        {
          duota_lentele[duotas_x+1][duotas_y]="·";
          if(duotas_y+1!=11) duota_lentele[duotas_x+1][duotas_y+1]="·";
          if(duotas_y-1!=0) duota_lentele[duotas_x+1][duotas_y-1]="·";
        }
      }
    }
    else if(duota_kryptis=="2")
    {
      if(duotas_x+(duotas_ilgis-1)>10) return false;
      for(int i=0; i<duotas_ilgis; i++)
      if(duota_lentele[duotas_x+i][duotas_y]=="■"||duota_lentele[duotas_x+i][duotas_y]=="·") return false;
      for(int j=0; j<duotas_ilgis; j++)
      {
        duota_lentele[duotas_x+j][duotas_y]="■";
        if(duotas_y+1!=11) duota_lentele[duotas_x+j][duotas_y+1]="·";
        if(duotas_y-1!=0) duota_lentele[duotas_x+j][duotas_y-1]="·";
        if(duotas_x-j-1!=0&&j==0)
        {
          duota_lentele[duotas_x-j-1][duotas_y]="·";
          if(duotas_y+1!=11) duota_lentele[duotas_x-j-1][duotas_y+1]="·";
          if(duotas_y-1!=0) duota_lentele[duotas_x-j-1][duotas_y-1]="·";
        }
        if(duotas_x+j+1!=11&&j==duotas_ilgis-1)
        {
          duota_lentele[duotas_x+j+1][duotas_y]="·";
          if(duotas_y+1!=11) duota_lentele[duotas_x+j+1][duotas_y+1]="·";
          if(duotas_y-1!=0) duota_lentele[duotas_x+j+1][duotas_y-1]="·";
        }
      }
    }
    else if(duota_kryptis=="3")
    {
      if(duotas_y+(duotas_ilgis-1)>10) return false;
      for(int i=0; i<duotas_ilgis; i++)
      if(duota_lentele[duotas_x][duotas_y+i]=="■"||duota_lentele[duotas_x][duotas_y+i]=="·") return false;
      for(int j=0; j<duotas_ilgis; j++)
      {
        duota_lentele[duotas_x][duotas_y+j]="■";
        if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y+j]="·";
        if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y+j]="·";
        if(duotas_y+j+1!=11&&j==duotas_ilgis-1)
        {
          duota_lentele[duotas_x][duotas_y+j+1]="·";
          if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y+j+1]="·";
          if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y+j+1]="·";
        }
        if(duotas_y-1!=0&&j==0)
        {
          duota_lentele[duotas_x][duotas_y-j-1]="·";
          if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y-j-1]="·";
          if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y-j-1]="·";
        }
      }
    }
    else if(duota_kryptis=="4")
    {
      if(duotas_y-(duotas_ilgis-1)<1) return false;
      for(int i=0; i<duotas_ilgis; i++)
      if(duota_lentele[duotas_x][duotas_y-i]=="■"||duota_lentele[duotas_x][duotas_y-i]=="·") return false;
      for(int j=0; j<duotas_ilgis; j++)
      {
        duota_lentele[duotas_x][duotas_y-j]="■";
        if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y-j]="·";
        if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y-j]="·";
        if(duotas_y+1!=11&&j==0)
        {
          duota_lentele[duotas_x][duotas_y+j+1]="·";
          if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y+j+1]="·";
          if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y+j+1]="·";
        }
        if(duotas_y-j-1!=0&&j==duotas_ilgis-1)
        {
          duota_lentele[duotas_x][duotas_y-j-1]="·";
          if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y-j-1]="·";
          if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y-j-1]="·";
        }
      }
    }
    else return false;
    return true;
  }

  void lenteles_valymas(string duota_lentele[][11])
  {
    for(int i=0; i<11; i++)
    for(int j=0; j<11; j++)
    if(duota_lentele[i][j]=="·") duota_lentele[i][j]="☐";
  }

  void lenteles_rodymas(string duota_lentele[][11])
  {
    cout<<endl;
    for(int i=0; i<11; i++)
    {
      for(int j=0; j<11; j++)
      {
        if(j==0) cout<<setw(2)<<duota_lentele[i][j]<<" ";
        else cout<<setw(1)<<duota_lentele[i][j]<<" ";
      }
      cout<<endl;
    }
  }

  int laivo_tikrinimas(int duotas_x, int duotas_y, string duota_lentele[][11])
  {
    int laivo_ilgis=1;
    for(int i=1; i<10; i++)
    if(duota_lentele[duotas_x-i][duotas_y]=="■") laivo_ilgis++;
    else if(duota_lentele[duotas_x-i][duotas_y]=="X") ;
    else break;
    for(int i=1; i<10; i++)
    if(duota_lentele[duotas_x+i][duotas_y]=="■") laivo_ilgis++;
    else if(duota_lentele[duotas_x+i][duotas_y]=="X") ;
    else break;
    for(int i=1; i<10; i++)
    if(duota_lentele[duotas_x][duotas_y+i]=="■") laivo_ilgis++;
    else if(duota_lentele[duotas_x][duotas_y+i]=="X") ;
    else break;
    for(int i=1; i<10; i++)
    if(duota_lentele[duotas_x][duotas_y-i]=="■") laivo_ilgis++;
    else if(duota_lentele[duotas_x][duotas_y-i]=="X") ;
    else break;
    return laivo_ilgis;
  }

  int laivo_kryptis(int duotas_x, int duotas_y, string duota_lentele[][11])
  {
    int temp_kryptis;
    if(duotas_x-1!=0&&duota_lentele[duotas_x-1][duotas_y]=="X") temp_kryptis=1;
    if(duotas_x+1!=11&&duota_lentele[duotas_x+1][duotas_y]=="X") temp_kryptis=2;
    if(duotas_y+1!=11&&duota_lentele[duotas_x][duotas_y+1]=="X") temp_kryptis=3;
    if(duotas_y-1!=0&&duota_lentele[duotas_x][duotas_y-1]=="X") temp_kryptis=4;
    return temp_kryptis;
  }

  bool galimybes_tikrinimas(int komp_x, int komp_y, vector<int> laivai, string zaidejo_lentele[][11])
  {
    int ilgiausias=laivai.back();
    bool galimybes[4]={true, true, true, true};
    for(int i=0; i<ilgiausias; i++)
    {
      if(zaidejo_lentele[komp_x-1][komp_y]==""||komp_x-1==0) galimybes[0]=false;
      if(zaidejo_lentele[komp_x+1][komp_y]==""||komp_x-1==11) galimybes[1]=false;
      if(zaidejo_lentele[komp_x][komp_y+1]==""||komp_y+1==11) galimybes[2]=false;
      if(zaidejo_lentele[komp_x][komp_y-1]==""||komp_y-1==0) galimybes[3]=false;
    }
    for(int j=0; j<4; j++)
    {
      if(galimybes[j]==true) return true;
    }
    return false;
  }

  void laivo_naikinimas(int duotas_x, int duotas_y, int duota_kryptis, string duota_lentele[][11], vector<int> laivai)
  {
    int pateiktas_ilgis=0;
    if(duota_kryptis==1)
    {
      for(int i=0; i<10; i++)
      {
        if(duotas_x-i!=0&&duota_lentele[duotas_x-i][duotas_y]=="X") pateiktas_ilgis++;
        else break;
      }
      for(int i=0; i<laivai.size(); i++)
      {
        if(laivai[i]==pateiktas_ilgis)
        {
          laivai.erase(laivai.begin()+i);
          break;
        }
      }
      for(int j=0; j<pateiktas_ilgis; j++)
      {
        duota_lentele[duotas_x-j][duotas_y]="♦";
        if(duotas_y+1!=11) duota_lentele[duotas_x-j][duotas_y+1]="";
        if(duotas_y-1!=0) duota_lentele[duotas_x-j][duotas_y-1]="";
        if(duotas_x-j-1!=0&&j==pateiktas_ilgis-1)
        {
          duota_lentele[duotas_x-j-1][duotas_y]="";
          if(duotas_y+1!=11) duota_lentele[duotas_x-j-1][duotas_y+1]="";
          if(duotas_y-1!=0) duota_lentele[duotas_x-j-1][duotas_y-1]="";
        }
        if(duotas_x+1!=11&&j==0)
        {
          duota_lentele[duotas_x+1][duotas_y]="";
          if(duotas_y+1!=11) duota_lentele[duotas_x+1][duotas_y+1]="";
          if(duotas_y-1!=0) duota_lentele[duotas_x+1][duotas_y-1]="";
        }
      }
    }
    if(duota_kryptis==2)
    {
      for(int i=0; i<10; i++)
      {
        if(duotas_x+i!=11&&duota_lentele[duotas_x+i][duotas_y]=="X") pateiktas_ilgis++;
        else break;
      }
      for(int i=0; i<laivai.size(); i++)
      {
        if(laivai[i]==pateiktas_ilgis)
        {
          laivai.erase(laivai.begin()+i);
          break;
        }
      }
      for(int j=0; j<pateiktas_ilgis; j++)
      {
        duota_lentele[duotas_x+j][duotas_y]="♦";
        if(duotas_y+1!=11) duota_lentele[duotas_x+j][duotas_y+1]="";
        if(duotas_y-1!=0) duota_lentele[duotas_x+j][duotas_y-1]="";
        if(duotas_x-j-1!=0&&j==0)
        {
          duota_lentele[duotas_x-j-1][duotas_y]="";
          if(duotas_y+1!=11) duota_lentele[duotas_x-j-1][duotas_y+1]="";
          if(duotas_y-1!=0) duota_lentele[duotas_x-j-1][duotas_y-1]="";
        }
        if(duotas_x+j+1!=11&&j==pateiktas_ilgis-1)
        {
          duota_lentele[duotas_x+j+1][duotas_y]="";
          if(duotas_y+1!=11) duota_lentele[duotas_x+j+1][duotas_y+1]="";
          if(duotas_y-1!=0) duota_lentele[duotas_x+j+1][duotas_y-1]="";
        }
      }
    }
    if(duota_kryptis==3)
    {
      for(int i=0; i<10; i++)
      {
        if(duotas_y+i!=11&&duota_lentele[duotas_x][duotas_y+i]=="X") pateiktas_ilgis++;
        else break;
      }
      for(int i=0; i<laivai.size(); i++)
      {
        if(laivai[i]==pateiktas_ilgis)
        {
          laivai.erase(laivai.begin()+i);
          break;
        }
      }
      for(int j=0; j<pateiktas_ilgis; j++)
      {
        duota_lentele[duotas_x][duotas_y+j]="♦";
        if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y+j]="";
        if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y+j]="";
        if(duotas_y+j+1!=11&&j==pateiktas_ilgis-1)
        {
          duota_lentele[duotas_x][duotas_y+j+1]="";
          if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y+j+1]="";
          if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y+j+1]="";
        }
        if(duotas_y-1!=0&&j==0)
        {
          duota_lentele[duotas_x][duotas_y-j-1]="";
          if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y-j-1]="";
          if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y-j-1]="";
        }
      }
    }
    if(duota_kryptis==4)
    {
      for(int i=0; i<10; i++)
      {
        if(duotas_y!=0&&duota_lentele[duotas_x][duotas_y-i]=="X") pateiktas_ilgis++;
        else break;
      }
      for(int i=0; i<laivai.size(); i++)
      {
        if(laivai[i]==pateiktas_ilgis)
        {
          laivai.erase(laivai.begin()+i);
          break;
        }
      }
      for(int j=0; j<pateiktas_ilgis; j++)
      {
        duota_lentele[duotas_x][duotas_y-j]="♦";
        if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y-j]="";
        if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y-j]="";
        if(duotas_y+1!=11&&j==0)
        {
          duota_lentele[duotas_x][duotas_y+j+1]="";
          if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y+j+1]="";
          if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y+j+1]="";
        }
        if(duotas_y-j-1!=0&&j==pateiktas_ilgis-1)
        {
          duota_lentele[duotas_x][duotas_y-j-1]="";
          if(duotas_x-1!=0) duota_lentele[duotas_x-1][duotas_y-j-1]="";
          if(duotas_x+1!=11) duota_lentele[duotas_x+1][duotas_y-j-1]="";
        }
      }
    }
  }
};

class kompiuterio: public bazine
{
  public:
  void kompiuterio_laivu_sudejimas(string duota_lentele[][11])
  {
    Carrier:
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    if(koordinates_tikrinimas(x, y, duota_lentele)==false) goto Carrier;
    kryptis = rand() % 4 + 1;
    krypties_konvertavimas(kryptis, ivesta_kryptis);
    if(pozicijos_galimumas(x, y, 5, ivesta_kryptis, duota_lentele)==false) goto Carrier;
    Battleship:
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    if(koordinates_tikrinimas(x, y, duota_lentele)==false) goto Battleship;
    kryptis = rand() % 4 + 1;
    krypties_konvertavimas(kryptis, ivesta_kryptis);
    if(pozicijos_galimumas(x, y, 4, ivesta_kryptis, duota_lentele)==false) goto Battleship;
    Cruiser:
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    if(koordinates_tikrinimas(x, y, duota_lentele)==false) goto Cruiser;
    kryptis = rand() % 4 + 1;
    krypties_konvertavimas(kryptis, ivesta_kryptis);
    if(pozicijos_galimumas(x, y, 3, ivesta_kryptis, duota_lentele)==false) goto Cruiser;
    Submarine:
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    if(koordinates_tikrinimas(x, y, duota_lentele)==false) goto Submarine;
    kryptis = rand() % 4 + 1;
    krypties_konvertavimas(kryptis, ivesta_kryptis);
    if(pozicijos_galimumas(x, y, 3, ivesta_kryptis, duota_lentele)==false) goto Submarine;
    Destroyer:
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    if(koordinates_tikrinimas(x, y, duota_lentele)==false) goto Destroyer;
    kryptis = rand() % 4 + 1;
    krypties_konvertavimas(kryptis, ivesta_kryptis);
    if(pozicijos_galimumas(x, y, 2, ivesta_kryptis, duota_lentele)==false) goto Destroyer;
  }

  void krypties_konvertavimas(int duota_kryptis, string &nauja_kryptis)
  {
    if(duota_kryptis==1) nauja_kryptis="1";
    if(duota_kryptis==2) nauja_kryptis="2";
    if(duota_kryptis==3) nauja_kryptis="3";
    if(duota_kryptis==4) nauja_kryptis="4";
  }

  int krypties_reversija(int duota_kryptis)
  {
    int nauja_kryptis;
    if(duota_kryptis==1) nauja_kryptis=2;
    if(duota_kryptis==2) nauja_kryptis=1;
    if(duota_kryptis==3) nauja_kryptis=4;
    if(duota_kryptis==4) nauja_kryptis=3;
    return nauja_kryptis;
  }
};

class zaidejo: public kompiuterio
{
  public:
  void zaidejo_laivu_sudejimas()
  {
    cout<<endl<<"Tai yra Jusu lentele."<<endl;
    lenteles_rodymas(zaidejo_lentele);
    Sudejimas:
    cout<<endl<<"Ar noretumete, kad laivai butu sudeti automatiskai (Y/N)?"<<endl<<"Atsakymas: ";
    cin>>sudetis;
    sudetis[0]=toupper(sudetis[0]);
    if(sudetis=="Y")
    {
      kompiuterio_laivu_sudejimas(zaidejo_lentele);
      return;
    }
    else if(sudetis!="N")
    {
      cout<<endl<<"Bloga ivestis! Bandykite is naujo."<<endl;
      goto Sudejimas;
    }
    cout<<endl<<"Sudekite savo laivus."<<endl;
    Carrier:
    cout<<endl<<"Kur noretumete padeti penkiavieti laiva 'Carrier' (Pvz.: I5)"<<endl<<"Atsakymas: ";
    cin>>ivesta_pozicija;
    if(ivedimo_tikrinimas(ivesta_pozicija)==true) pozicijos_isgavimas();
    else
    {
      cout<<endl<<"Bloga ivestis! Bandykite is naujo."<<endl;
      goto Carrier;
    }
    if(koordinates_tikrinimas(x, y, zaidejo_lentele)==false)
    {
      cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
      goto Carrier;
    }
    cout<<endl<<"Kokia kryptimi norite padeti laiva? (1 - virsus, 2- apacia, 3 - desine, 4 - kaire)"<<endl<<"Atsakymas: ";
    cin>>ivesta_kryptis;
    if(pozicijos_galimumas(x, y, 5, ivesta_kryptis, zaidejo_lentele)==false)
    {
      cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
      goto Carrier;
    }
    lenteles_rodymas(zaidejo_lentele);
    Battleship:
    cout<<endl<<"Kur noretumete padeti keturvieti laiva 'Battleship' (Pvz.: I5)"<<endl<<"Atsakymas: ";
    cin>>ivesta_pozicija;
    if(ivedimo_tikrinimas(ivesta_pozicija)==true) pozicijos_isgavimas();
    else
    {
      cout<<endl<<"Bloga ivestis! Bandykite is naujo."<<endl;
      goto Battleship;
    }
    if(koordinates_tikrinimas(x, y, zaidejo_lentele)==false)
    {
      cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
      goto Battleship;
    }
    cout<<endl<<"Kokia kryptimi norite padeti laiva? (1 - virsus, 2- apacia, 3 - desine, 4 - kaire)"<<endl<<"Atsakymas: ";
    cin>>ivesta_kryptis;
    if(pozicijos_galimumas(x, y, 4, ivesta_kryptis, zaidejo_lentele)==false)
    {
      cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
      goto Battleship;
    }
    lenteles_rodymas(zaidejo_lentele);
    Cruiser:
    cout<<endl<<"Kur noretumete padeti trivieti laiva 'Cruiser' (Pvz.: I5)"<<endl<<"Atsakymas: ";
    cin>>ivesta_pozicija;
    if(ivedimo_tikrinimas(ivesta_pozicija)==true) pozicijos_isgavimas();
    else
    {
      cout<<endl<<"Bloga ivestis! Bandykite is naujo."<<endl;
      goto Cruiser;
    }
    if(koordinates_tikrinimas(x, y, zaidejo_lentele)==false)
    {
      cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
      goto Cruiser;
    }
    cout<<endl<<"Kokia kryptimi norite padeti laiva? (1 - virsus, 2- apacia, 3 - desine, 4 - kaire)"<<endl<<"Atsakymas: ";
    cin>>ivesta_kryptis;
    if(pozicijos_galimumas(x, y, 3, ivesta_kryptis, zaidejo_lentele)==false)
    {
      cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
      goto Cruiser;
    }
    lenteles_rodymas(zaidejo_lentele);
    Submarine:
    cout<<endl<<"Kur noretumete padeti trivieti laiva 'Submarine' (Pvz.: I5)"<<endl<<"Atsakymas: ";
    cin>>ivesta_pozicija;
    if(ivedimo_tikrinimas(ivesta_pozicija)==true) pozicijos_isgavimas();
    else
    {
      cout<<endl<<"Bloga ivestis! Bandykite is naujo."<<endl;
      goto Submarine;
    }
    if(koordinates_tikrinimas(x, y, zaidejo_lentele)==false)
    {
      cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
      goto Submarine;
    }
    cout<<endl<<"Kokia kryptimi norite padeti laiva? (1 - virsus, 2- apacia, 3 - desine, 4 - kaire)"<<endl<<"Atsakymas: ";
    cin>>ivesta_kryptis;
    if(pozicijos_galimumas(x, y, 3, ivesta_kryptis, zaidejo_lentele)==false)
    {
      cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
      goto Submarine;
    }
    lenteles_rodymas(zaidejo_lentele);
    Destroyer:
    cout<<endl<<"Kur noretumete padeti trivieti laiva 'Submarine' (Pvz.: I5)"<<endl<<"Atsakymas: ";
    cin>>ivesta_pozicija;
    if(ivedimo_tikrinimas(ivesta_pozicija)==true) pozicijos_isgavimas();
    else
    {
      cout<<endl<<"Bloga ivestis! Bandykite is naujo."<<endl;
      goto Destroyer;
    }
    if(koordinates_tikrinimas(x, y, zaidejo_lentele)==false)
    {
      cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
      goto Destroyer;
    }
    cout<<endl<<"Kokia kryptimi norite padeti laiva? (1 - virsus, 2- apacia, 3 - desine, 4 - kaire)"<<endl<<"Atsakymas: ";
    cin>>ivesta_kryptis;
    if(pozicijos_galimumas(x, y, 2, ivesta_kryptis, zaidejo_lentele)==false)
    {
      cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
      goto Destroyer;
    }
    lenteles_rodymas(zaidejo_lentele);
  }

  void pozicijos_isgavimas()
  {
    ivesta_pozicija[0]=toupper(ivesta_pozicija[0]);
    for(int i=0; i<11; i++)
    for(int j=0; j<11; j++)
    {
      if(zaidejo_lentele[i][j].substr(0, 2)==ivesta_pozicija.substr(1, 2)) x=i;
      if(zaidejo_lentele[i][j].substr(0, 2)==ivesta_pozicija.substr(0, 1)) y=j;
    }
  }

  void koordinates_keitimas(int &duotas_x, int &duotas_y, int duota_kryptis, string duota_lentele[][11])
  {
    if(duota_kryptis==1)
    {
      for(int i=0; i<10; i++)
      if(duota_lentele[duotas_x-1][duotas_y]=="X"&&duotas_x-1!=0) duotas_x--;
      else break;
    }
    if(duota_kryptis==2)
    {
      for(int i=0; i<10; i++)
      if(duota_lentele[duotas_x+1][duotas_y]=="X"&&duotas_x+1!=11) duotas_x++;
      else break;
    }
    if(duota_kryptis==3)
    {
      for(int i=0; i<10; i++)
      if(duota_lentele[duotas_x][duotas_y+1]=="X"&&duotas_y+1!=11) duotas_y++;
      else break;
    }
    if(duota_kryptis==4)
    {
      for(int i=0; i<10; i++)
      if(duota_lentele[duotas_x][duotas_y-1]=="X"&&duotas_y-1!=0) duotas_y--;
      else break;
    }
  }
};

class musio: public zaidejo
{
  private:
  int a, b, zaidejo_taskai, kompiuterio_taskai;

  public:
  musio():zaidejo_taskai(0), kompiuterio_taskai(0){}
  musio(int a, int b):zaidejo_taskai(a), kompiuterio_taskai(b){}
  ~musio(){}

  void karas()
  {
    bool pataikymas, komp_pataike_1=false, komp_pataike_2=false;
    int sekanti_koord=0, temp_x=0, temp_y=0, temp_ilgis=0, komp_x=0, komp_y=0;
    kompiuterio_laivu_sudejimas(kompiuterio_lentele);
    cout<<endl<<"Kompiuteris taip pat sudejo savo laivus."<<endl;
    lenteles_valymas(zaidejo_lentele);
    lenteles_valymas(kompiuterio_lentele);
    cout<<endl<<"Pradekime musi!"<<endl;
    sleep(1);
    cout<<endl<<"Zaidejo lentele:"<<endl;
    lenteles_rodymas(zaidejo_lentele);
    cout<<endl<<"Kompiuterio lentele:"<<endl;
    lenteles_rodymas(zaidejo_spejimai);
    Musis:
    if(ejimas=="zaidejo") ejimas="kompiuterio";
    else ejimas="zaidejo";
    if(ejimas=="zaidejo")
    {
      Zaidejas:
      if(zaidejo_taskai==17)
      {
        cout<<endl<<"Jus laimejote!"<<endl;
        return;
      }
      cout<<endl<<"Pasirinkite pozicija, i kuria noretumete sauti (Pvz: I5)"<<endl<<"Atsakymas: ";
      cin>>ivesta_pozicija;
      if(ivedimo_tikrinimas(ivesta_pozicija)==true) pozicijos_isgavimas();
      else
      {
        cout<<endl<<"Bloga ivestis! Bandykite is naujo."<<endl;
        goto Zaidejas;
      }
      if(x>10||y>10||x<1||y<1)
      {
        cout<<endl<<"Pozicija negalima! Bandykite is naujo."<<endl;
        goto Zaidejas;
      }
      if(kompiuterio_lentele[x][y]=="■")
      {
        kompiuterio_lentele[x][y]="X";
        zaidejo_spejimai[x][y]="X";
        pataikymas=true;
        zaidejo_taskai++;
      }
      else if(kompiuterio_lentele[x][y]=="☐"||kompiuterio_lentele[x][y]=="·")
      {
        kompiuterio_lentele[x][y]="";
        zaidejo_spejimai[x][y]="";
        pataikymas=false;
      }
      else
      {
        cout<<endl<<"I sia pozicija jau sovete! Pasirinkite kita."<<endl;
        goto Zaidejas;
      }
      if(pataikymas==true&&laivo_tikrinimas(x, y, kompiuterio_lentele)==1)
      {
        kryptis=laivo_kryptis(x, y, zaidejo_spejimai);
        koordinates_keitimas(x, y, kryptis, zaidejo_spejimai);
        kryptis=laivo_kryptis(x, y, zaidejo_spejimai);
        laivo_naikinimas(x, y, kryptis, zaidejo_spejimai, komp_laivai);
      }
      sleep(1);
      cout<<endl<<"Zaidejo lentele:"<<endl;
      lenteles_rodymas(zaidejo_lentele);
      cout<<endl<<"Kompiuterio lentele:"<<endl;
      lenteles_rodymas(zaidejo_spejimai);
      if(pataikymas==true) goto Zaidejas;
      else goto Musis;
    }
    if(ejimas=="kompiuterio")
    {
      Kompiuteris:
      if(kompiuterio_taskai==17)
      {
        cout<<endl<<"Deja, laimejo kompiuteris."<<endl;
        return;
      }
      if(komp_pataike_1==false&&komp_pataike_2==false)
      {
        komp_x = rand() % 10 + 1;
        komp_y = rand() % 10 + 1;
        if(galimybes_tikrinimas(komp_x, komp_y, zaid_laivai, zaidejo_lentele)==false) goto Kompiuteris;
        if(zaidejo_lentele[komp_x][komp_y]=="■")
        {
          zaidejo_lentele[komp_x][komp_y]="X";
          komp_pataike_1=true;
          pataikymas=true;
          kompiuterio_taskai++;
        }
        else if(zaidejo_lentele[komp_x][komp_y]=="☐"||zaidejo_lentele[komp_x][komp_y]=="·")
        {
          zaidejo_lentele[komp_x][komp_y]="";
          pataikymas=false;
        }
        else goto Kompiuteris;
        sleep(1);
        cout<<endl<<"Zaidejo lentele:"<<endl;
        lenteles_rodymas(zaidejo_lentele);
        cout<<endl<<"Kompiuterio lentele:"<<endl;
        lenteles_rodymas(zaidejo_spejimai);
        if(pataikymas==true) goto Kompiuteris;
        else goto Musis;
      }
      if(komp_pataike_1==true)
      {
        Tinkamumas:
        sekanti_koord = rand() % 4 + 1;
        if(sekanti_koord==1&&komp_x-1!=0&&zaidejo_lentele[komp_x-1][komp_y]!="")
        {
          temp_x=komp_x-1;
          temp_y=komp_y;
        }
        else if(sekanti_koord==2&&komp_x+1!=11&&zaidejo_lentele[komp_x+1][komp_y]!="")
        {
          temp_x=komp_x+1;
          temp_y=komp_y;
        }
        else if(sekanti_koord==3&&komp_y+1!=11&&zaidejo_lentele[komp_x][komp_y+1]!="")
        {
          temp_x=komp_x;
          temp_y=komp_y+1;
        }
        else if(sekanti_koord==4&&komp_y-1!=0&&zaidejo_lentele[komp_x][komp_y-1]!="")
        {
          temp_x=komp_x;
          temp_y=komp_y-1;
        }
        else goto Tinkamumas;
        if(zaidejo_lentele[temp_x][temp_y]=="■")
        {
          zaidejo_lentele[temp_x][temp_y]="X";
          komp_pataike_1=false;
          komp_pataike_2=true;
          pataikymas=true;
          kompiuterio_taskai++;
        }
        else if(zaidejo_lentele[temp_x][temp_y]=="☐"||zaidejo_lentele[temp_x][temp_y]=="·")
        {
          zaidejo_lentele[temp_x][temp_y]="";
          pataikymas=false;
        }
        if(pataikymas==true&&laivo_tikrinimas(temp_x, temp_y, zaidejo_lentele)==1)
        {
          kryptis=laivo_kryptis(temp_x, temp_y, zaidejo_lentele);
          laivo_naikinimas(temp_x, temp_y, kryptis, zaidejo_lentele, zaid_laivai);
          komp_pataike_2=false;
        }
        sleep(1);
        cout<<endl<<"Zaidejo lentele:"<<endl;
        lenteles_rodymas(zaidejo_lentele);
        cout<<endl<<"Kompiuterio lentele:"<<endl;
        lenteles_rodymas(zaidejo_spejimai);
        if(pataikymas==true) goto Kompiuteris;
        else goto Musis;
      }
      if(komp_pataike_2==true)
      {
        Keitimas:
        if(sekanti_koord==1)
        {
          if(temp_x-1!=0&&zaidejo_lentele[temp_x-1][temp_y]!="") temp_x--;
          else
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            pataikymas=true;
            goto Keitimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="■")
          {
            zaidejo_lentele[temp_x][temp_y]="X";
            pataikymas=true;
            kompiuterio_taskai++;
            goto Tesimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="☐"||zaidejo_lentele[temp_x][temp_y]=="·")
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            zaidejo_lentele[temp_x][temp_y]="";
            pataikymas=false;
            goto Tesimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="X") goto Keitimas;
        }
        if(sekanti_koord==2)
        {
          if(temp_x+1!=11&&zaidejo_lentele[temp_x+1][temp_y]!="") temp_x++;
          else
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            pataikymas=true;
            goto Keitimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="■")
          {
            zaidejo_lentele[temp_x][temp_y]="X";
            pataikymas=true;
            kompiuterio_taskai++;
            goto Tesimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="☐"||zaidejo_lentele[temp_x][temp_y]=="·")
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            zaidejo_lentele[temp_x][temp_y]="";
            pataikymas=false;
            goto Tesimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="X") goto Keitimas;
        }
        if(sekanti_koord==3)
        {
          if(temp_y+1!=11&&zaidejo_lentele[temp_x][temp_y+1]!="") temp_y++;
          else
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            pataikymas=true;
            goto Keitimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="■")
          {
            zaidejo_lentele[temp_x][temp_y]="X";
            pataikymas=true;
            kompiuterio_taskai++;
            goto Tesimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="☐"||zaidejo_lentele[temp_x][temp_y]=="·")
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            zaidejo_lentele[temp_x][temp_y]="";
            pataikymas=false;
            goto Tesimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="X") goto Keitimas;
        }
        if(sekanti_koord==4)
        {
          if(temp_y-1!=0&&zaidejo_lentele[temp_x][temp_y-1]!="") temp_y--;
          else
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            pataikymas=true;
            goto Keitimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="■")
          {
            zaidejo_lentele[temp_x][temp_y]="X";
            pataikymas=true;
            kompiuterio_taskai++;
            goto Tesimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="☐"||zaidejo_lentele[temp_x][temp_y]=="·")
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            zaidejo_lentele[temp_x][temp_y]="";
            pataikymas=false;
            goto Tesimas;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="X") goto Keitimas;
        }
        Tesimas:
        if(pataikymas==true&&laivo_tikrinimas(temp_x, temp_y, zaidejo_lentele)==1)
        {
          kryptis=laivo_kryptis(temp_x, temp_y, zaidejo_lentele);
          laivo_naikinimas(temp_x, temp_y, kryptis, zaidejo_lentele, zaid_laivai);
          komp_pataike_2=false;
        }
        sleep(1);
        cout<<endl<<"Zaidejo lentele:"<<endl;
        lenteles_rodymas(zaidejo_lentele);
        cout<<endl<<"Kompiuterio lentele:"<<endl;
        lenteles_rodymas(zaidejo_spejimai);
        if(pataikymas==true) goto Kompiuteris;
        else goto Musis;
      }
    }
  }
};

int main()
{
  string status;
  musio klase;
  srand (time(NULL));
  cout<<endl<<"Sveiki atvyke i zaidima 'Laivu musis'! © Edvin Zdanovic, 2019"<<endl;
  Pagrindinis:
  klase.lenteliu_kurimas();
  klase.zaidejo_laivu_sudejimas();
  klase.karas();
  cout<<endl<<"Zaidimas baigtas."<<endl;
  Pasirinkimas:
  cout<<endl<<"Ar norite zaisti vel? (Y/N)"<<endl<<"Atsakymas: ";
  cin>>status;
  status[0]=toupper(status[0]);
  if(status=="Y") goto Pagrindinis;
  else if(status!="N")
  {
    cout<<endl<<"Bloga ivestis! Bandykite is naujo."<<endl;
    goto Pasirinkimas;
  }
  return 0;
}
