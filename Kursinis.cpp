#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class laivu_musis
{
  private:
  int x, y, ilgis, kryptis;
  string ivesta_pozicija, ivesta_kryptis, ejimas;
  string zaidejo_lentele[11][11];
  string kompiuterio_lentele[11][11];
  string zaidejo_spejimai[11][11];

  public:
  void lenteliu_kurimas()
  {
    int raides=0, skaiciai=0;
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
  }

  void zaidejo_laivu_sudejimas()
  {
    cout<<endl<<"Tai yra Jusu lentele. Sudekite savo laivus."<<endl;
    zaidejo_lenteles_rodymas();
    Carrier:
    cout<<endl<<"Kur noretumete padeti penkiavieti laiva 'Carrier' (Pvz.: I5)"<<endl<<"Atsakymas: ";
    cin>>ivesta_pozicija;
    pozicijos_isgavimas();
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
    zaidejo_lenteles_rodymas();
    Battleship:
    cout<<endl<<"Kur noretumete padeti keturvieti laiva 'Battleship' (Pvz.: I5)"<<endl<<"Atsakymas: ";
    cin>>ivesta_pozicija;
    pozicijos_isgavimas();
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
    zaidejo_lenteles_rodymas();
    Cruiser:
    cout<<endl<<"Kur noretumete padeti trivieti laiva 'Cruiser' (Pvz.: I5)"<<endl<<"Atsakymas: ";
    cin>>ivesta_pozicija;
    pozicijos_isgavimas();
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
    zaidejo_lenteles_rodymas();
    Submarine:
    cout<<endl<<"Kur noretumete padeti trivieti laiva 'Submarine' (Pvz.: I5)"<<endl<<"Atsakymas: ";
    cin>>ivesta_pozicija;
    pozicijos_isgavimas();
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
    zaidejo_lenteles_rodymas();
    Destroyer:
    cout<<endl<<"Kur noretumete padeti trivieti laiva 'Submarine' (Pvz.: I5)"<<endl<<"Atsakymas: ";
    cin>>ivesta_pozicija;
    pozicijos_isgavimas();
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
    zaidejo_lenteles_rodymas();
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

  bool koordinates_tikrinimas(int x, int y, string lentele[][11])
  {
    if(x>10||y>10||x<1||y<1) return false;
    if(lentele[x][y]=="■"||lentele[x][y]=="·") return false;
    return true;
  }

  bool pozicijos_galimumas(int x, int y, int ilgis, string ivesta_kryptis, string lentele[][11])
  {
    if(ivesta_kryptis!="1"&&ivesta_kryptis!="2"&&ivesta_kryptis!="3"&&ivesta_kryptis!="4") return false;
    if(ivesta_kryptis=="1")
    {
      if(x-(ilgis-1)<1) return false;
      for(int i=0; i<ilgis; i++)
      if(lentele[x-i][y]=="■"||lentele[x-i][y]=="·") return false;
      for(int j=0; j<ilgis; j++)
      {
        lentele[x-j][y]="■";
        if(y+1!=11) lentele[x-j][y+1]="·";
        if(y-1!=0) lentele[x-j][y-1]="·";
        if(x-j-1!=0&&j==ilgis-1)
        {
          lentele[x-j-1][y]="·";
          if(y+1!=11) lentele[x-j-1][y+1]="·";
          if(y-1!=0) lentele[x-j-1][y-1]="·";
        }
        if(x+1!=11&&j==0)
        {
          lentele[x+1][y]="·";
          if(y+1!=11) lentele[x+1][y+1]="·";
          if(y-1!=0) lentele[x+1][y-1]="·";
        }
      }
    }
    if(ivesta_kryptis=="2")
    {
      if(x+(ilgis-1)>10) return false;
      for(int i=0; i<ilgis; i++)
      if(lentele[x+i][y]=="■"||lentele[x+i][y]=="·") return false;
      for(int j=0; j<ilgis; j++)
      {
        lentele[x+j][y]="■";
        if(y+1!=11) lentele[x+j][y+1]="·";
        if(y-1!=0) lentele[x+j][y-1]="·";
        if(x-j-1!=0&&j==0)
        {
          lentele[x-j-1][y]="·";
          if(y+1!=11) lentele[x-j-1][y+1]="·";
          if(y-1!=0) lentele[x-j-1][y-1]="·";
        }
        if(x+j+1!=11&&j==ilgis-1)
        {
          lentele[x+j+1][y]="·";
          if(y+1!=11) lentele[x+j+1][y+1]="·";
          if(y-1!=0) lentele[x+j+1][y-1]="·";
        }
      }
    }
    if(ivesta_kryptis=="3")
    {
      if(y+(ilgis-1)>10) return false;
      for(int i=0; i<ilgis; i++)
      if(lentele[x][y+i]=="■"||lentele[x][y+i]=="·") return false;
      for(int j=0; j<ilgis; j++)
      {
        lentele[x][y+j]="■";
        if(x-1!=0) lentele[x-1][y+j]="·";
        if(x+1!=11) lentele[x+1][y+j]="·";
        if(y+j+1!=11&&j==ilgis-1)
        {
          lentele[x][y+j+1]="·";
          if(x-1!=0) lentele[x-1][y+j+1]="·";
          if(x+1!=11) lentele[x+1][y+j+1]="·";
        }
        if(y-1!=0&&j==0)
        {
          lentele[x][y-j-1]="·";
          if(x-1!=0) lentele[x-1][y-j-1]="·";
          if(x+1!=11) lentele[x+1][y-j-1]="·";
        }
      }
    }
    if(ivesta_kryptis=="4")
    {
      if(y-(ilgis-1)<1) return false;
      for(int i=0; i<ilgis; i++)
      if(lentele[x][y-i]=="■"||lentele[x][y-i]=="·") return false;
      for(int j=0; j<ilgis; j++)
      {
        lentele[x][y-j]="■";
        if(x-1!=0) lentele[x-1][y-j]="·";
        if(x+1!=11) lentele[x+1][y-j]="·";
        if(y+1!=11&&j==0)
        {
          lentele[x][y+j+1]="·";
          if(x-1!=0) lentele[x-1][y+j+1]="·";
          if(x+1!=11) lentele[x+1][y+j+1]="·";
        }
        if(y-j-1!=0&&j==ilgis-1)
        {
          lentele[x][y-j-1]="·";
          if(x-1!=0) lentele[x-1][y-j-1]="·";
          if(x+1!=11) lentele[x+1][y-j-1]="·";
        }
      }
    }
    return true;
  }

  void zaidejo_lenteles_rodymas()
  {
    cout<<endl;
    for(int i=0; i<11; i++)
    {
      for(int j=0; j<11; j++)
      {
        if(j==0) cout<<setw(2)<<zaidejo_lentele[i][j]<<" ";
        else cout<<setw(1)<<zaidejo_lentele[i][j]<<" ";
      }
      cout<<endl;
    }
  }

  void kompiuterio_laivu_sudejimas()
  {
    srand (time(NULL));
    cout<<endl<<"Kompiuteris taip pat sudejo savo laivus."<<endl;
    Carrier:
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    if(koordinates_tikrinimas(x, y, kompiuterio_lentele)==false) goto Carrier;
    kryptis = rand() % 4 + 1;
    krypties_konvertavimas(kryptis, ivesta_kryptis);
    if(pozicijos_galimumas(x, y, 5, ivesta_kryptis, kompiuterio_lentele)==false) goto Carrier;
    Battleship:
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    if(koordinates_tikrinimas(x, y, kompiuterio_lentele)==false) goto Battleship;
    kryptis = rand() % 4 + 1;
    krypties_konvertavimas(kryptis, ivesta_kryptis);
    if(pozicijos_galimumas(x, y, 4, ivesta_kryptis, kompiuterio_lentele)==false) goto Battleship;
    Cruiser:
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    if(koordinates_tikrinimas(x, y, kompiuterio_lentele)==false) goto Cruiser;
    kryptis = rand() % 4 + 1;
    krypties_konvertavimas(kryptis, ivesta_kryptis);
    if(pozicijos_galimumas(x, y, 3, ivesta_kryptis, kompiuterio_lentele)==false) goto Cruiser;
    Submarine:
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    if(koordinates_tikrinimas(x, y, kompiuterio_lentele)==false) goto Submarine;
    kryptis = rand() % 4 + 1;
    krypties_konvertavimas(kryptis, ivesta_kryptis);
    if(pozicijos_galimumas(x, y, 3, ivesta_kryptis, kompiuterio_lentele)==false) goto Submarine;
    Destroyer:
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    if(koordinates_tikrinimas(x, y, kompiuterio_lentele)==false) goto Destroyer;
    kryptis = rand() % 4 + 1;
    krypties_konvertavimas(kryptis, ivesta_kryptis);
    if(pozicijos_galimumas(x, y, 2, ivesta_kryptis, kompiuterio_lentele)==false) goto Destroyer;
  }

  void krypties_konvertavimas(int kryptis, string &ivesta_kryptis)
  {
    if(kryptis==1) ivesta_kryptis="1";
    if(kryptis==2) ivesta_kryptis="2";
    if(kryptis==3) ivesta_kryptis="3";
    if(kryptis==4) ivesta_kryptis="4";
  }

  void kompiuterio_lenteles_rodymas()
  {
    cout<<endl;
    for(int i=0; i<11; i++)
    {
      for(int j=0; j<11; j++)
      {
        if(j==0) cout<<setw(2)<<kompiuterio_lentele[i][j]<<" ";
        else cout<<setw(1)<<kompiuterio_lentele[i][j]<<" ";
      }
      cout<<endl;
    }
  }

  void karas()
  {
    bool pataikymas, komp_pataike_1=false, komp_pataike_2=false;
    int zaidejo_taskai=0, kompiuterio_taskai=0;
    int sekanti_koord, temp_x, temp_y, temp_ilgis, komp_x, komp_y;
    cout<<endl<<"Pradekime musi!"<<endl;
    Musis:
    ejimu_kaita();
    if(ejimas=="zaidejo")
    {
      cout<<endl<<"Zaidejo lentele:"<<endl;
      zaidejo_lenteles_rodymas();
      cout<<endl<<"Kompiuterio lentele:"<<endl;
      zaidejo_spejimu_rodymas();
      Zaidejas:
      if(zaidejo_taskai==17)
      {
        cout<<endl<<"Jus laimejote!"<<endl;
        return;
      }
      cout<<endl<<"Pasirinkite pozicija, i kuria noretumete sauti (Pvz: I5)"<<endl<<"Atsakymas: ";
      cin>>ivesta_pozicija;
      pozicijos_isgavimas();
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
        laivo_naikinimas(x, y, kryptis, zaidejo_spejimai);
      }
      cout<<endl<<"Zaidejo lentele:"<<endl;
      zaidejo_lenteles_rodymas();
      cout<<endl<<"Kompiuterio lentele:"<<endl;
      zaidejo_spejimu_rodymas();
      if(pataikymas==true) goto Zaidejas;
      else goto Musis;
    }
    if(ejimas=="kompiuterio")
    {
      cout<<endl<<"Zaidejo lentele:"<<endl;
      zaidejo_lenteles_rodymas();
      cout<<endl<<"Kompiuterio lentele:"<<endl;
      zaidejo_spejimu_rodymas();
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
        cout<<endl<<"Zaidejo lentele:"<<endl;
        zaidejo_lenteles_rodymas();
        cout<<endl<<"Kompiuterio lentele:"<<endl;
        zaidejo_spejimu_rodymas();
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
          laivo_naikinimas(temp_x, temp_y, kryptis, zaidejo_lentele);
          komp_pataike_2=false;
        }
        cout<<endl<<"Zaidejo lentele:"<<endl;
        zaidejo_lenteles_rodymas();
        cout<<endl<<"Kompiuterio lentele:"<<endl;
        zaidejo_spejimu_rodymas();
        if(pataikymas==true) goto Kompiuteris;
        else goto Musis;
      }
      if(komp_pataike_2==true)
      {
        if(sekanti_koord==1)
        {
          if(temp_x-1!=0&&zaidejo_lentele[temp_x-1][temp_y]!="") temp_x--;
          else
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            pataikymas=true;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="■")
          {
            zaidejo_lentele[temp_x][temp_y]="X";
            pataikymas=true;
            kompiuterio_taskai++;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="☐"||zaidejo_lentele[temp_x][temp_y]=="·")
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            zaidejo_lentele[temp_x][temp_y]="";
            pataikymas=false;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="X") pataikymas=true;
        }
        if(sekanti_koord==2)
        {
          if(temp_x+1!=11&&zaidejo_lentele[temp_x+1][temp_y]!="") temp_x++;
          else
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            pataikymas=true;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="■")
          {
            zaidejo_lentele[temp_x][temp_y]="X";
            pataikymas=true;
            kompiuterio_taskai++;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="☐"||zaidejo_lentele[temp_x][temp_y]=="·")
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            zaidejo_lentele[temp_x][temp_y]="";
            pataikymas=false;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="X") pataikymas=true;
        }
        if(sekanti_koord==3)
        {
          if(temp_y+1!=11&&zaidejo_lentele[temp_x][temp_y+1]!="") temp_y++;
          else
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            pataikymas=true;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="■")
          {
            zaidejo_lentele[temp_x][temp_y]="X";
            pataikymas=true;
            kompiuterio_taskai++;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="☐"||zaidejo_lentele[temp_x][temp_y]=="·")
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            zaidejo_lentele[temp_x][temp_y]="";
            pataikymas=false;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="X") pataikymas=true;
        }
        if(sekanti_koord==4)
        {
          if(temp_y-1!=0&&zaidejo_lentele[temp_x][temp_y-1]!="") temp_y--;
          else
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            pataikymas=true;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="■")
          {
            zaidejo_lentele[temp_x][temp_y]="X";
            pataikymas=true;
            kompiuterio_taskai++;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="☐"||zaidejo_lentele[temp_x][temp_y]=="·")
          {
            sekanti_koord=krypties_reversija(sekanti_koord);
            zaidejo_lentele[temp_x][temp_y]="";
            pataikymas=false;
          }
          if(zaidejo_lentele[temp_x][temp_y]=="X") pataikymas=true;
        }
        if(pataikymas==true&&laivo_tikrinimas(temp_x, temp_y, zaidejo_lentele)==1)
        {
          kryptis=laivo_kryptis(temp_x, temp_y, zaidejo_lentele);
          laivo_naikinimas(temp_x, temp_y, kryptis, zaidejo_lentele);
          komp_pataike_2=false;
        }
        cout<<endl<<"Zaidejo lentele:"<<endl;
        zaidejo_lenteles_rodymas();
        cout<<endl<<"Kompiuterio lentele:"<<endl;
        zaidejo_spejimu_rodymas();
        if(pataikymas==true) goto Kompiuteris;
        else goto Musis;
      }
    }
  }

  void ejimu_kaita()
  {
    if(ejimas=="zaidejo") ejimas="kompiuterio";
    else ejimas="zaidejo";
  }

  int laivo_tikrinimas(int x, int y, string lentele[][11])
  {
    int ilgis=1;
    for(int i=1; i<10; i++)
    if(lentele[x-i][y]=="■") ilgis++;
    else if(lentele[x-i][y]=="X") ;
    else break;
    for(int i=1; i<10; i++)
    if(lentele[x+i][y]=="■") ilgis++;
    else if(lentele[x+i][y]=="X") ;
    else break;
    for(int i=1; i<10; i++)
    if(lentele[x][y+i]=="■") ilgis++;
    else if(lentele[x][y+i]=="X") ;
    else break;
    for(int i=1; i<10; i++)
    if(lentele[x][y-i]=="■") ilgis++;
    else if(lentele[x][y-i]=="X") ;
    else break;
    return ilgis;
  }

  int laivo_kryptis(int x, int y, string lentele[][11])
  {
    int kryptis;
    if(lentele[x-1][y]=="X") kryptis=1;
    if(lentele[x+1][y]=="X") kryptis=2;
    if(lentele[x][y+1]=="X") kryptis=3;
    if(lentele[x][y-1]=="X") kryptis=4;
    return kryptis;
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

  int krypties_reversija(int pateikta_kryptis)
  {
    int nauja_kryptis;
    if(pateikta_kryptis==1) nauja_kryptis=2;
    if(pateikta_kryptis==2) nauja_kryptis=1;
    if(pateikta_kryptis==3) nauja_kryptis=4;
    if(pateikta_kryptis==4) nauja_kryptis=3;
    return nauja_kryptis;
  }

  void laivo_naikinimas(int duotas_x, int duotas_y, int pateikta_kryptis, string lentele[][11])
  {
    int pateiktas_ilgis=0;
    if(pateikta_kryptis==1)
    {
      for(int i=0; i<10; i++)
      {
        if(lentele[duotas_x-i][duotas_y]=="X") pateiktas_ilgis++;
        else break;
      }
      for(int j=0; j<pateiktas_ilgis; j++)
      {
        lentele[duotas_x-j][duotas_y]="♦";
        if(duotas_y+1!=11) lentele[duotas_x-j][duotas_y+1]="";
        if(duotas_y-1!=0) lentele[duotas_x-j][duotas_y-1]="";
        if(duotas_x-j-1!=0&&j==pateiktas_ilgis-1)
        {
          lentele[duotas_x-j-1][duotas_y]="";
          if(duotas_y+1!=11) lentele[duotas_x-j-1][duotas_y+1]="";
          if(duotas_y-1!=0) lentele[duotas_x-j-1][duotas_y-1]="";
        }
        if(duotas_x+1!=11&&j==0)
        {
          lentele[duotas_x+1][duotas_y]="";
          if(duotas_y+1!=11) lentele[duotas_x+1][duotas_y+1]="";
          if(duotas_y-1!=0) lentele[duotas_x+1][duotas_y-1]="";
        }
      }
    }
    if(pateikta_kryptis==2)
    {
      for(int i=0; i<10; i++)
      {
        if(lentele[duotas_x+i][duotas_y]=="X") pateiktas_ilgis++;
        else break;
      }
      for(int j=0; j<pateiktas_ilgis; j++)
      {
        lentele[duotas_x+j][duotas_y]="♦";
        if(duotas_y+1!=11) lentele[duotas_x+j][duotas_y+1]="";
        if(duotas_y-1!=0) lentele[duotas_x+j][duotas_y-1]="";
        if(duotas_x-j-1!=0&&j==0)
        {
          lentele[duotas_x-j-1][duotas_y]="";
          if(duotas_y+1!=11) lentele[duotas_x-j-1][duotas_y+1]="";
          if(duotas_y-1!=0) lentele[duotas_x-j-1][duotas_y-1]="";
        }
        if(duotas_x+j+1!=11&&j==pateiktas_ilgis-1)
        {
          lentele[duotas_x+j+1][duotas_y]="";
          if(duotas_y+1!=11) lentele[duotas_x+j+1][duotas_y+1]="";
          if(duotas_y-1!=0) lentele[duotas_x+j+1][duotas_y-1]="";
        }
      }
    }
    if(pateikta_kryptis==3)
    {
      for(int i=0; i<10; i++)
      {
        if(lentele[duotas_x][duotas_y+i]=="X") pateiktas_ilgis++;
        else break;
      }
      for(int j=0; j<pateiktas_ilgis; j++)
      {
        lentele[duotas_x][duotas_y+j]="♦";
        if(duotas_x-1!=0) lentele[duotas_x-1][duotas_y+j]="";
        if(duotas_x+1!=11) lentele[duotas_x+1][duotas_y+j]="";
        if(duotas_y+j+1!=11&&j==pateiktas_ilgis-1)
        {
          lentele[duotas_x][duotas_y+j+1]="";
          if(duotas_x-1!=0) lentele[duotas_x-1][duotas_y+j+1]="";
          if(duotas_x+1!=11) lentele[duotas_x+1][duotas_y+j+1]="";
        }
        if(duotas_y-1!=0&&j==0)
        {
          lentele[duotas_x][duotas_y-j-1]="";
          if(duotas_x-1!=0) lentele[duotas_x-1][duotas_y-j-1]="";
          if(duotas_x+1!=11) lentele[duotas_x+1][duotas_y-j-1]="";
        }
      }
    }
    if(pateikta_kryptis==4)
    {
      for(int i=0; i<10; i++)
      {
        if(lentele[duotas_x][duotas_y-i]=="X") pateiktas_ilgis++;
        else break;
      }
      for(int j=0; j<pateiktas_ilgis; j++)
      {
        lentele[duotas_x][duotas_y-j]="♦";
        if(duotas_x-1!=0) lentele[duotas_x-1][duotas_y-j]="";
        if(duotas_x+1!=11) lentele[duotas_x+1][duotas_y-j]="";
        if(duotas_y+1!=11&&j==0)
        {
          lentele[duotas_x][duotas_y+j+1]="";
          if(duotas_x-1!=0) lentele[duotas_x-1][duotas_y+j+1]="";
          if(duotas_x+1!=11) lentele[duotas_x+1][duotas_y+j+1]="";
        }
        if(duotas_y-j-1!=0&&j==pateiktas_ilgis-1)
        {
          lentele[duotas_x][duotas_y-j-1]="";
          if(duotas_x-1!=0) lentele[duotas_x-1][duotas_y-j-1]="";
          if(duotas_x+1!=11) lentele[duotas_x+1][duotas_y-j-1]="";
        }
      }
    }
  }

  void zaidejo_spejimu_rodymas()
  {
    cout<<endl;
    for(int i=0; i<11; i++)
    {
      for(int j=0; j<11; j++)
      {
        if(j==0) cout<<setw(2)<<zaidejo_spejimai[i][j]<<" ";
        else cout<<setw(1)<<zaidejo_spejimai[i][j]<<" ";
      }
      cout<<endl;
    }
  }
};

int main()
{
  string status;
  laivu_musis klase;
  cout<<endl<<"Sveiki atvyke i zaidima 'Laivu musis'! © Edvin Zdanovic, 2019"<<endl;
  Pagrindinis:
  klase.lenteliu_kurimas();
  klase.zaidejo_laivu_sudejimas();
  klase.kompiuterio_laivu_sudejimas();
  klase.karas();
  cout<<endl<<"Zaidimas baigtas. Ar norite zaisti vel? (Y/N)"<<endl<<"Atsakymas: ";
  cin>>status;
  status[0]=toupper(status[0]);
  if(status=="Y") goto Pagrindinis;
  else return 0;
}
