//library
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

using namespace std;
//penyimpanan sementara game (struct)
struct node{
    int value;
    struct node*next;
};

struct player{
    string pengguna;
    struct player*terus;
};

struct playerRanked{
    int level;
    struct playerRanked*after;
};

struct leaderboard
{
    string levelku;
    struct leaderboard * skuy;
};

//Struk node
struct node *head = NULL;
struct node *tail = NULL;

//Struct player
player *kepala = NULL;
player *belakang = NULL;

//struct playerRanked
playerRanked *ketua = NULL;
playerRanked *pegawai = NULL;

//struct leaderboard
leaderboard *maju = NULL;
leaderboard *mundur = NULL;


int score = 0;
int xScore = 69; // kanan kiri
int yScore = 2; // atas bawah


// movement function
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool isEmpty()
{

    return head ==NULL;
    return kepala == NULL;
}

bool isKosong()
{
    return kepala == NULL;
    return belakang == NULL;
}

bool nol()
{
    return ketua == NULL;
    return pegawai == NULL;
}

bool zero()
{
    return maju == NULL;
    return mundur == NULL;
}
//insert skor


void insertPlayer(string data){ //memasukan nama ke memori


if(isKosong())
{
    player *bantuan = new player();
    bantuan->pengguna=data;
    bantuan->terus=NULL;
    kepala = bantuan;
    belakang=bantuan;

}
else
{
    player*bantuan = new player();
    bantuan->pengguna = data;
    bantuan->terus=NULL;
    belakang->terus=bantuan;
    belakang=bantuan;

}

}

void insertPlayerSkor(int data){ //memasukan nama ke memori


if(nol())
{
    playerRanked *bantuan = new playerRanked();
    bantuan->level=data;
    bantuan->after=NULL;
    ketua = bantuan;
    pegawai=bantuan;

}
else
{
    playerRanked *bantuan = new playerRanked();
    bantuan->level = data;
    bantuan->after=NULL;
    pegawai->after=bantuan;
    pegawai=bantuan;

}
}


void insertPlayerRanked(string data){ //memasukan nama ke memori


if(zero())
{
    leaderboard *bantuan = new leaderboard();
    bantuan->levelku=data;
    bantuan->skuy=NULL;
    maju = bantuan;
    mundur=bantuan;

}
else
{
    leaderboard*bantuan = new leaderboard();
    bantuan->levelku = data;
    bantuan->skuy=NULL;
    mundur->skuy=bantuan;
    mundur=bantuan;

}
}

void masukanNama()
{
    string nama;
    gotoxy(2,27);cin >> nama;
    insertPlayer(nama);

}

void masukanNamaRanked()
{
    string nama;
    gotoxy(2,27);cin >> nama;
    insertPlayerRanked(nama);

}

void resetMasukanNama() // menghapus nama di bawah
{
    for(int i =2;i<10;i++)
    {
        gotoxy(i,27);printf(" ");
    }
}

void resetHistory()
{
    int j = 1;
    for(int i =4;i<10;i++)
    {
        gotoxy(i,j);printf(" ");
        j++;
    }
}
//insert nama
void insert(int data){
    if(isEmpty())
    {
        node*bantuan = new node();
        bantuan->value=data;
        bantuan->next=NULL;
        head = bantuan;
        tail=bantuan;
    }
    else
    {
        node*bantuan = new node();
        bantuan->value = data;
        bantuan->next=NULL;
        tail->next=bantuan;
        tail=bantuan;

    }
}

void display()
{
     if(isEmpty())
    {


    }
    else
    {
            node *isi = new node;
        isi = head;
        //xScore = 69;
        while(isi!=NULL)
        {

            //xScore--;
             isi = isi->next;
        }
    }

}

void displayHistory() // menampilkan nama di samping
{
     player *isi = new player;
    isi = kepala;

   int nomer = 10;
    //xScore = 69;

    while(isi!=NULL)
    {
        gotoxy(75,nomer);cout<<isi->pengguna;
        //xScore--;
         isi = isi->terus;
         nomer++;
    }
    resetMasukanNama();
}

void displayHistorySkor(int baris,int kolom) // menampilkan nama di samping
{
     playerRanked *isi = new playerRanked;
    isi = ketua;

    //xScore = 69;

    while(isi!=NULL)
    {
        gotoxy(baris,kolom);cout<<isi->level;
        //xScore--;
         isi = isi->after;

    }
}

void displayHistoryRanked() // menampilkan nama di samping
{
   leaderboard *isi = new leaderboard;
    isi = maju;

   int nomer = 10;
    //xScore = 69;

    while(isi!=NULL)
    {
        gotoxy(75,nomer);cout<<isi->levelku;
        //xScore--;
         isi = isi->skuy;
         nomer++;
    }
    resetMasukanNama();
}

void hapusLeaderboard()
{


         leaderboard *key=maju; // kita deklarasikan terlebih dahulu variabel key dengan tipe data sruct node yang dimana isi dari key sama denga head
         leaderboard *previous=NULL; //kita deklarasikan kembali varibel previus dengan tipe data struck yang dimana memiliki value sama dengan null

         if(isEmpty())
         {


         }
         else
         {
                while(key!=NULL) //ulangi ketika key tidak sama dengan null
                {

                    previous=key; // disini kita isi variabel previous dengan copas data key yang memiliki data head
                    previous=previous->skuy; // setelah itu kita pindahkan variabel previus ke pendatang 1 sehingga previus berpindah urutan 2
                    maju=previous; // setelah berpindah pendatang 1 itu kita jadikan head
                    free(key); // kemudian kita panggil fungsi c++ untuk menghapus key


                    break; // kita break agar langsung berhenti tidak melooping lag

                 }
                    previous=key; // kita samakan variabel baru previous dengan key
                    key=key->skuy; // kita pindahkan variabel key ke pendatang baru
         }



}


void hapusResetHistory()
{


         player *key=kepala; // kita deklarasikan terlebih dahulu variabel key dengan tipe data sruct node yang dimana isi dari key sama denga head
         player *previous=NULL; //kita deklarasikan kembali varibel previus dengan tipe data struck yang dimana memiliki value sama dengan null

         if(isEmpty())
         {


         }
         else
         {
                while(key!=NULL) //ulangi ketika key tidak sama dengan null
                {

                    previous=key; // disini kita isi variabel previous dengan copas data key yang memiliki data head
                    previous=previous->terus; // setelah itu kita pindahkan variabel previus ke pendatang 1 sehingga previus berpindah urutan 2
                    kepala=previous; // setelah berpindah pendatang 1 itu kita jadikan head
                    free(key); // kemudian kita panggil fungsi c++ untuk menghapus key


                    break; // kita break agar langsung berhenti tidak melooping lag

                 }
                    previous=key; // kita samakan variabel baru previous dengan key
                    key=key->terus; // kita pindahkan variabel key ke pendatang baru
         }



}



void hapus(int data)
{

         node *key=head; // kita deklarasikan terlebih dahulu variabel key dengan tipe data sruct node yang dimana isi dari key sama denga head
         node *previous=NULL; //kita deklarasikan kembali varibel previus dengan tipe data struck yang dimana memiliki value sama dengan null

         if(isEmpty())
         {


         }
         else
         {
                 while(key!=NULL) //ulangi ketika key tidak sama dengan null
                {

               if(key->value = data)
               {
                previous=key; // disini kita isi variabel previous dengan copas data key yang memiliki data head
                previous=previous->next; // setelah itu kita pindahkan variabel previus ke pendatang 1 sehingga previus berpindah urutan 2
                head=previous; // setelah berpindah pendatang 1 itu kita jadikan head
                free(key); // kemudian kita panggil fungsi c++ untuk menghapus key


                break; // kita break agar langsung berhenti tidak melooping lag

               }
                previous=key; // kita samakan variabel baru previous dengan key
                key=key->next; // kita pindahkan variabel key ke pendatang baru


                }
         }


}

void hapusReset()
{


         node *key=head; // kita deklarasikan terlebih dahulu variabel key dengan tipe data sruct node yang dimana isi dari key sama denga head
         node *previous=NULL; //kita deklarasikan kembali varibel previus dengan tipe data struck yang dimana memiliki value sama dengan null

         if(isEmpty())
         {


         }
         else
         {
                while(key!=NULL) //ulangi ketika key tidak sama dengan null
                {

                    previous=key; // disini kita isi variabel previous dengan copas data key yang memiliki data head
                    previous=previous->next; // setelah itu kita pindahkan variabel previus ke pendatang 1 sehingga previus berpindah urutan 2
                    head=previous; // setelah berpindah pendatang 1 itu kita jadikan head
                    free(key); // kemudian kita panggil fungsi c++ untuk menghapus key


                    break; // kita break agar langsung berhenti tidak melooping lag

                 }
                    previous=key; // kita samakan variabel baru previous dengan key
                    key=key->next; // kita pindahkan variabel key ke pendatang baru
         }



}


// slow down anim
void slow()
{
    float a = 1;
    do
    {
        a = a + 0.05;
    } while (a < 1000000);
}
// arena
void arena()
{
    for (int i = 2; i < 69; i++)
    {
        for (int j = 4; j < 23; j++)
        {
            gotoxy(i, j);
            cout << " ";
        }
    }
}
// arena boundary
void bounds()
{
    gotoxy(1, 1);
    printf("%c", 218);
    gotoxy(1, 24);
    printf("%c", 192);
    gotoxy(21,2);printf("AASDW = Bergerak; ESC = Keluar");
    for (int x = 2; x < 70; x++)
    {
        gotoxy(x, 1);
        printf("%c", 196);
        gotoxy(x,3);printf("%c",196);
        gotoxy(x, 24);
        printf("%c", 196);
    }
    gotoxy(70, 1);
    printf("%c", 191);
    gotoxy(70, 24);
    printf("%c", 217);
    for (int y = 2; y < 24; y++)
    {
        gotoxy(1, y);
        printf("%c", 179);
        gotoxy(70, y);
        printf("%c", 179);
    }
}
int acakX()

{
    int x=rand();
    if((x%69)<2)
        return(x%69)+2;
    else
        return (x%69);
}
int acakY()
{
    int y = rand();
    if((y%23)<5)
        return(y%23)+5;
    else
        return (y%23);
}

void papanSkorAtas()
{
    //batas atas
    for(int i=75;i<=94;i++)
    {
        gotoxy(i,3);
        printf("-");
        gotoxy(i,17);
        printf("-");
        gotoxy(i,5);
        printf("-");
        gotoxy(75,4);
        printf("Informasi");
        //delay();
    }

}

void papanSkorBawah()
{
   //batas samping
    for(int i = 3;i<=17;i++)
    {
        gotoxy(74,i);
        printf("|");
        gotoxy(94,i);
        printf("|");
        //delay();
    }
}

void papaKeteranganAtas()
{
    //batas atas keterangan
    for(int i=75;i<=93;i++)
    {

        gotoxy(i,19);
        printf("-");
        gotoxy(i,24);
        printf("-");
        gotoxy(i,21);
        printf("-");
        gotoxy(76,20);
        printf("Keterangan");

        //pelanggaran
        gotoxy(75,6);cout<<"Pelanggaaran";
        gotoxy(i,8);
        printf("-");

        //cheat
        gotoxy(75,9);
        printf("History");

        //delay();
    }
}

void papaKeteranganBawah()
{
    //batas samping
    for(int i = 19;i<=24;i++)
    {
        gotoxy(74,i);
        printf("|");
        gotoxy(94,i);
        printf("|");
        //delay();
    }
}


//agar bergerak
void delay(void)
{
    int delay;
    delay = 1;
    while(delay<100000000)
    {
        delay++;
    }
}

void opening()
{
    int i,j;
    char ulang;

    for(i=40;i<=75;i++)
    {
        gotoxy(i,12);
        printf("-");
        gotoxy(i,14);
        printf("-");
        system("color 2");
        delay();
    }
    for(i=1;i<100;i++)
    {
        gotoxy(49,13);
        cout << "L O A D I N G "<<i<<"%";
        delay();
    }
    system("cls");


}



void bingkaiAtasGame()
{
    //system("color 2");
    for(int i=1;i<=100;i++)
    {
        gotoxy(i,1);
        printf("-");
        gotoxy(i,25);
        printf("-");
        gotoxy(i,29);
        printf("-");
        //delay();
    }
}

void bingkaiSampingGame()
{
    for(int i=1;i<=29;i++)
    {
        gotoxy(1,i);
        printf("|");
        gotoxy(100,i);
        printf("|");
       // delay();
    }
}



void nama()
{

            gotoxy(2,26);
            cout << "masukan nama anda";
           masukanNama();



}

void namaRanked()
{

            gotoxy(2,26);
            cout << "masukan nama anda";
           masukanNamaRanked();



}


string cobaNama;
void delaySkor(void)
{
    int delay;
    delay = 1;
    while(delay<300000000)
    {
        delay++;
    }
}

void game()
{
    reset :
    bingkaiAtasGame();
    bingkaiSampingGame();

    nama();
    displayHistory();

    //menjalankan fungsi pencet keyboard
    char key;


   // int cheat=0;

                    int xHero = 10;
                    int yHero = 7;
                    int xHeroPrev = xHero+1;
                    int yHeroPrev = yHero;

                    int tAtas =3;
                    int tBawah =24;
                    int tKanan=70;
                    int tKiri = 1;


                    float xEnemy=60;
                    float yEnemy=20;
                    float xEnemyPrev=xEnemy;
                    float yEnemyPrev = yEnemy;
                    float lEnemy =0.3;


                    //int xScore = 69; // kanan kiri
                    //int yScore = 2; // atas bawah

                    srand(time(0));
                    int xFruit = acakX();
                    int yFruit = acakY();

                    //skor
                    int i = 0;

                    arena();
                    bounds();

                    gotoxy(xFruit,yFruit);cout << "*";
                    //dumy cek detik
                    float cariDetik=0;

                    papanSkorAtas();
                    papanSkorBawah();
                    papaKeteranganAtas();
                    papaKeteranganBawah();
                    int nyawaPlayer = 0;



                    do
                    {
                        //deteksi keyboard
                        if(kbhit())
                        key = getch();


                            //mulai cek detik
                            cariDetik+=0.1;

                            //cheat mereset waktu jadi 0 kembali apabila mencet T
                            if(toupper(int(key))==84)
                            {
                                 cariDetik=0;
                            }

                            gotoxy(3,4);printf("detik : %.0f  ",cariDetik);
                            if((int)cariDetik>=10)
                            {
                                cariDetik=0;
                                if(xScore<69)
                                {
                                    score--;
                                    xScore++;
                                    gotoxy(xScore,yScore);cout << " ";
                                }
                            }
                        //informasi posisi
                        //gotoxy(1,1);printf("posisi Hero : [%d,%d]",xHero,yHero);
                        //gotoxy(40,1);printf("posisi prev Hero : [%d,%d]",xHeroPrev,yHeroPrev);

                         //menghilang hero
                        gotoxy(xHeroPrev,yHeroPrev);printf(" ");

                        //menghilangkan musuh
                        gotoxy(xEnemyPrev,yEnemyPrev);printf(" ");

                        //memunculkan hero
                        gotoxy(xHero,yHero);
                        //system("color A1");  ganti warna
                        printf("H");
                        //memunculkan musuh
                        gotoxy(xEnemy,yEnemy);printf("O");


                        //deteksi tombol


                        if(toupper(key)=='A')
                        {
                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            xHero--;
                            if(xHero<=tKiri)
                                xHero=tKiri+1;

                        }
                        if(toupper(key)=='S')
                        {
                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            yHero++;
                            if(yHero>=tBawah)
                                yHero=tBawah-1;
                        }
                        if(toupper(key)=='D')
                        {
                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            xHero++;
                            if(xHero>=tKanan)
                                xHero=tKanan-1;

                        }
                        if(toupper(key)=='W')
                        {
                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            yHero--;
                            if(yHero<=tAtas)
                                yHero=tAtas+1;
                        }
                        //cheat

                        if(toupper(int(key))==88) // cheat teleport jika pencet tombol X
                        {


                                gotoxy(xHero,yHero);printf(" ");
                                xHero = xFruit-1;
                                yHero = yFruit-1;



                        }

                        //Algoritma kejar hero

                        //atas

                         if(yEnemy<yHero + lEnemy) // enemy diatas hero
                        {
                            yEnemyPrev = yEnemy;
                            yEnemy+=lEnemy;

                        }
                         else if(yEnemy>yHero)  //enemy di bawah hero
                        {
                            yEnemyPrev = yEnemy;
                            yEnemy-=lEnemy;

                        }
                         if(xEnemy<xHero + lEnemy)  //enemy di kiri hero
                        {
                            xEnemyPrev = xEnemy;
                            xEnemy+=lEnemy;

                        }

                         else if(xEnemy>xHero)  //enemy di kanan hero
                        {
                            xEnemyPrev = xEnemy;

                            xEnemy-=lEnemy;

                        }






                        //deteksi buah dimakan hero

                        if((xHero==xFruit)&&(yHero ==yFruit))
                        {

                            score++;
                            insert(i);
                           gotoxy(xScore,yScore);cout<<score;
                            display();
                            if(score>=5)
                            {
                                gotoxy(10,10);cout << "selamat anda memenanglan game ini";
                                displayHistory();

                                 char opsi;


                             gotoxy(76,22);cout<<"Coba Lagi (y/t)"<<endl;
                             gotoxy(77,23);cin>>opsi;
                             if(opsi=='y')
                             {
                               score = 0;
                                nyawaPlayer=0;

                                resetHistory(); // menghapus nama di bawah
                                hapusReset(); //menghapus semua score sehingga mengulang dari awal
                                system("cls");
                                goto reset;
                             }
                             if(opsi=='t')
                             {
                                 score = 0;
                                 nyawaPlayer=0;
                                hapusReset();
                                resetMasukanNama();

                                 break;
                             }
                                break;

                            }


                            hapus(i);
                            xScore--;
                            //xScore--;

                            xFruit =acakX();
                            yFruit = acakY();
                            gotoxy(xFruit,yFruit);

                            cout << "*";
                            cariDetik=0;
                        }

                         if(((int)xEnemy==xFruit)&&((int)yEnemy==yFruit))
                         {

                            xFruit = acakX();
                            yFruit = acakY();
                            gotoxy(xFruit,yFruit);cout << "*";
                         }

                         //terkena musuh terdapat pelanggaran bila sudah lebih dari 3  maka gagal
                         if((xHero==(int)xEnemy)&&(yHero==(int)yEnemy))
                         {

                             gotoxy(75,7);cout<<nyawaPlayer;
                             nyawaPlayer++;
                             xHero = acakX();
                             yHero = acakY();
                             gotoxy(75,7);cout<<nyawaPlayer;
                             char opsional;

                             if(nyawaPlayer == 3)
                             {


                                 gotoxy(76,22);cout<<"coba lagi (y/t)"<<endl;
                                 gotoxy(77,23);cin>>opsional;
                                 if(opsional == 'y')
                                 {

                                    score = 0;
                                    nyawaPlayer = 0;

                                     resetHistory();
                                     hapusReset();//menghapus data score pada linked list
                                    system("cls");
                                    goto reset;
                                 }
                                 if(opsional == 't')
                                 {
                                      score = 0;
                                         nyawaPlayer=0;
                                        hapusReset();
                                        break;

                                 }
                                 break;
                             }
                         }

                       slow();


                    } while (key != 27);



system("cls");
}

//game multiplayerBalapan
    char map[20][20];
    char Player = 'w';
    char Player2 = 'o';


    int x = 18;
    int y = 2;

    int x2 = 18;
    int y2 = 5;

    char walk;

void generateMap()
{
    for(int i = 0;i<20;i++)
    {
        for(int j =0;j<20;j++)
        {
            map[i][j]= ' ';
        }
    }
    map[x][y] = Player;
    map[x2][y2]=Player2;
}

void printMap()
{
    for(int i=0;i<20;i++)
    {
        for(int j = 0;j<20;j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

void gameMultiplayerBalapan()
{
    do
    {
        system("cls");
        generateMap();
        printMap();
        walk = getch();

        switch(walk)
        {
        case 'w' :
            if(map[x-1][y]==' ')
            {
                x--;
                map[x+1][y]=' ';
                map[x][y]=Player;
                break;
            }
        case 'o' :
            if(map[x-1][y]==' ')
            {
                x2--;
                map[x2+1][y2]=' ';
                map[x2][y2]=Player2;
                break;
            }
        }

    }while(y<20000);
    getchar();

   system("cls");
}


void gameMultiplayer()
{
    //system("color 9");
     reset :
    bingkaiAtasGame();
    bingkaiSampingGame();

    //menjalankan fungsi pencet keyboard
    char key;
    char key2;


         int xHero = 10;
         int yHero = 7;

         int xHero2 = 12;
         int yHero2 = 7;

         int xHeroPrev = xHero+1;
         int yHeroPrev = yHero;

         int xHeroPrev2 = xHero2+1;
         int yHeroPrev2 = yHero2;

         int tAtas =3;
         int tBawah =24;
         int tKanan=70;
         int tKiri = 1;

         float xEnemy=60;
         float yEnemy=20;
         float xEnemyPrev=xEnemy;
         float yEnemyPrev = yEnemy;
         float lEnemy =0.3;

         srand(time(0));
         int xFruit = acakX();
         int yFruit = acakY();

         //skor
         int i = 0;

         arena();
         bounds();

         gotoxy(xFruit,yFruit);cout << "*";
         //dumy cek detik
         float cariDetik=0;

         papanSkorAtas();
         papanSkorBawah();
         papaKeteranganAtas();
         papaKeteranganBawah();
         int nyawaPlayer = 0;

         do
        {
                        //deteksi keyboard
            if(kbhit())
            key = getch();





        //mulai cek detik
                            cariDetik+=0.1;

                            //cheat mereset waktu jadi 0 kembali apabila mencet T
                            if(toupper(int(key))==84)
                            {
                                 cariDetik=0;
                            }

                            gotoxy(3,4);printf("detik : %.0f  ",cariDetik);
                            if((int)cariDetik>=10)
                            {
                                cariDetik=0;
                                if(xScore<69)
                                {
                                    score--;
                                    xScore++;
                                    gotoxy(xScore,yScore);cout << " ";
                                }
                            }

                         //menghilang hero
                        gotoxy(xHeroPrev,yHeroPrev);printf(" ");

                        //menghilangkan hero2
                        gotoxy(xHeroPrev2,yHeroPrev2);printf(" ");

                        //menghilangkan musuh
                        gotoxy(xEnemyPrev,yEnemyPrev);printf(" ");

                        //memunculkan hero
                        gotoxy(xHero,yHero);printf("H");

                        //memunculkan hero2
                        gotoxy(xHero2,yHero2);printf("l");

                        //system("color A1");  ganti warna

                        //memunculkan musuh
                        gotoxy(xEnemy,yEnemy);printf("O");


                        //deteksi tombol

                        //player 1
                        switch(key)
                        {
                        case 'a' :

                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            xHero--;
                            if(xHero<=tKiri)
                                xHero=tKiri+1;
                                break;


                        case 's' :
                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            yHero++;
                            if(yHero>=tBawah)
                            yHero=tBawah-1;
                                break;
                        case 'd' :

                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            xHero++;
                            if(xHero>=tKanan)
                                xHero=tKanan-1;
                                break;
                        case 'w' :

                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            yHero--;
                            if(yHero<=tAtas)
                                yHero=tAtas+1;
                                break;

                        case 'j' :
                            xHeroPrev2 = xHero2;
                            yHeroPrev2 = yHero2;
                            xHero2--;
                            if(xHero2<=tKiri)
                                xHero2=tKiri+1;
                                break;
                        case 'k' :
                            xHeroPrev2 = xHero2;
                            yHeroPrev2 = yHero2;
                            yHero2++;
                            if(yHero2>=tBawah)
                                yHero2=tBawah-1;
                                break;
                        case 'l':
                             xHeroPrev2 = xHero2;
                            yHeroPrev2 = yHero2;
                            xHero2++;
                            if(xHero2>=tKanan)
                                xHero2=tKanan-1;
                                break;
                        case 'i' :
                            xHeroPrev2 = xHero2;
                            yHeroPrev2 = yHero2;
                            yHero2--;
                            if(yHero2<=tAtas)
                                yHero2=tAtas+1;
                                break;
                        }

                        //cheat

                        if(toupper(int(key))==88) // cheat teleport jika pencet tombol X
                        {


                                gotoxy(xHero,yHero);printf(" ");
                                xHero = xFruit-1;
                                yHero = yFruit-1;



                        }

                        //Algoritma kejar hero

                        //atas

                         if(yEnemy<yHero + lEnemy) // enemy diatas hero
                        {
                            yEnemyPrev = yEnemy;
                            yEnemy+=lEnemy;

                        }
                         else if(yEnemy>yHero)  //enemy di bawah hero
                        {
                            yEnemyPrev = yEnemy;
                            yEnemy-=lEnemy;

                        }
                         if(xEnemy<xHero + lEnemy)  //enemy di kiri hero
                        {
                            xEnemyPrev = xEnemy;
                            xEnemy+=lEnemy;

                        }

                         else if(xEnemy>xHero)  //enemy di kanan hero
                        {
                            xEnemyPrev = xEnemy;

                            xEnemy-=lEnemy;

                        }






                        //deteksi buah dimakan hero

                        if((xHero==xFruit)&&(yHero ==yFruit))
                        {

                            score++;
                            insert(i);
                           gotoxy(xScore,yScore);cout<<score;
                            display();
                            if(score>=5)
                            {
                                gotoxy(10,10);cout << "selamat anda memenanglan game ini";
                                displayHistory();

                                 char pilihan;


                             gotoxy(76,22);cout<<"Coba Lagi (y/t)"<<endl;
                             gotoxy(77,23);cin>>pilihan;
                             if(pilihan=='y')
                             {
                               score = 0;
                                nyawaPlayer=0;

                                resetHistory();
                                hapusReset();
                                system("cls");
                                goto reset;
                             }
                             if(pilihan=='t')
                             {
                                 score = 0;
                                 nyawaPlayer=0;
                                hapusReset();

                                 break;
                             }
                                break;

                            }


                            hapus(i);
                            xScore--;
                            //xScore--;

                            xFruit =acakX();
                            yFruit = acakY();
                            gotoxy(xFruit,yFruit);

                            cout << "*";
                            cariDetik=0;
                        }

                         if(((int)xEnemy==xFruit)&&((int)yEnemy==yFruit))
                         {

                            xFruit = acakX();
                            yFruit = acakY();
                            gotoxy(xFruit,yFruit);cout << "*";
                         }

                         //terkena musuh terdapat pelanggaran bila sudah lebih dari 3  maka gagal
                         if((xHero==(int)xEnemy)&&(yHero==(int)yEnemy))
                         {


                            gotoxy(75,7);cout<<nyawaPlayer;
                            nyawaPlayer++;
                            xHero = acakX();
                            yHero = acakY();
                            gotoxy(75,7);cout<<nyawaPlayer;

                            if(nyawaPlayer == 3)
                            {
                                        char pilihan;


                                     gotoxy(76,22);cout<<"Coba Lagi (y/t)"<<endl;
                                     gotoxy(77,23);cin>>pilihan;
                                     if(pilihan=='y')
                                     {
                                        score = 0;
                                        nyawaPlayer =0;

                                        resetHistory();
                                        hapusReset();
                                        system("cls");
                                        goto reset;
                                     }
                                      if(pilihan=='t')
                                     {
                                         score = 0;
                                         nyawaPlayer=0;
                                        hapusReset();

                                         break;
                                     }
                                     break;

                            }



                         }
                       slow();


                    } while ((key != 27) || (y<20000));
getchar();

system("cls");
}


void gameRanked()
{
    reset :
    namaRanked();
    int levelLeaderboard = 0;
     int levelPlayer = 0;
    int levelHistory = 0;
    int baris = 85;
    int kolom = 10;
    menang :
    int kolomLeaderboard = 10;
    bingkaiAtasGame();
    bingkaiSampingGame();


    displayHistoryRanked();


    //menjalankan fungsi pencet keyboard
    char key;



   // int cheat=0;

                    int xHero = 10;
                    int yHero = 7;
                    int xHeroPrev = xHero+1;
                    int yHeroPrev = yHero;

                    int tAtas =3;
                    int tBawah =24;
                    int tKanan=70;
                    int tKiri = 1;


                    float xEnemy=8;
                    float yEnemy=20;
                    float xEnemyPrev=xEnemy;
                    float yEnemyPrev = yEnemy;
                    float lEnemy;

                    if(levelPlayer == 0)
                    {
                         lEnemy =0.3;
                    }
                    else if (levelPlayer == 1)
                    {
                        lEnemy =0.4;
                    }
                    else if(levelPlayer == 2)
                    {
                        lEnemy =0.5;
                    }
                    else if(levelPlayer == 3)
                    {
                        lEnemy = 0.6;
                    }
                    else if(levelPlayer == 4)
                    {
                        lEnemy = 0.7;
                    }
                    else
                    {

                    }






                    //int xScore = 69; // kanan kiri
                    //int yScore = 2; // atas bawah

                    srand(time(0));
                    int xFruit = acakX();
                    int yFruit = acakY();

                    //skor
                    int i = 0;

                    arena();
                    bounds();

                    gotoxy(xFruit,yFruit);cout << "*";
                    //dumy cek detik
                    float cariDetik=0;

                    papanSkorAtas();
                    papanSkorBawah();
                    papaKeteranganAtas();
                    papaKeteranganBawah();
                    int nyawaPlayer = 0;

                    insertPlayerSkor(levelPlayer);
                    displayHistorySkor(baris,kolom);




                    do
                    {

                        //deteksi keyboard
                        if(kbhit())
                        key = getch();


                            //mulai cek detik
                            cariDetik+=0.1;

                            //cheat mereset waktu jadi 0 kembali apabila mencet T
                            if(toupper(int(key))==84)
                            {
                                 cariDetik=0;
                            }

                            gotoxy(3,4);printf("detik : %.0f  ",cariDetik);
                            if((int)cariDetik>=10)
                            {
                                cariDetik=0;
                                if(xScore<69)
                                {
                                    score--;
                                    xScore++;
                                    gotoxy(xScore,yScore);cout << " ";
                                }
                            }
                        //informasi posisi
                        //gotoxy(1,1);printf("posisi Hero : [%d,%d]",xHero,yHero);
                        //gotoxy(40,1);printf("posisi prev Hero : [%d,%d]",xHeroPrev,yHeroPrev);

                         //menghilang hero
                        gotoxy(xHeroPrev,yHeroPrev);printf(" ");

                        //menghilangkan musuh
                        gotoxy(xEnemyPrev,yEnemyPrev);printf(" ");


                        //memunculkan hero
                        gotoxy(xHero,yHero);
                        //system("color A1");  ganti warna
                        printf("H");
                        //memunculkan musuh
                        gotoxy(xEnemy,yEnemy);printf("O");





                        //deteksi tombol


                        if(toupper(key)=='A')
                        {
                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            xHero--;
                            if(xHero<=tKiri)
                                xHero=tKiri+1;

                        }
                        if(toupper(key)=='S')
                        {
                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            yHero++;
                            if(yHero>=tBawah)
                                yHero=tBawah-1;
                        }
                        if(toupper(key)=='D')
                        {
                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            xHero++;
                            if(xHero>=tKanan)
                                xHero=tKanan-1;

                        }
                        if(toupper(key)=='W')
                        {
                            xHeroPrev = xHero;
                            yHeroPrev = yHero;
                            yHero--;
                            if(yHero<=tAtas)
                                yHero=tAtas+1;
                        }
                        //cheat

                        if(toupper(int(key))==88) // cheat teleport jika pencet tombol X
                        {


                                gotoxy(xHero,yHero);printf(" ");
                                xHero = xFruit-1;
                                yHero = yFruit-1;



                        }

                        //Algoritma kejar hero

                        //atas

                        //musuh1

                         if(yEnemy<yHero + lEnemy) // enemy diatas hero
                        {
                            yEnemyPrev = yEnemy;
                            yEnemy+=lEnemy;

                        }
                         else if(yEnemy>yHero)  //enemy di bawah hero
                        {
                            yEnemyPrev = yEnemy;
                            yEnemy-=lEnemy;

                        }
                         if(xEnemy<xHero + lEnemy)  //enemy di kiri hero
                        {
                            xEnemyPrev = xEnemy;
                            xEnemy+=lEnemy;

                        }

                         else if(xEnemy>xHero)  //enemy di kanan hero
                        {
                            xEnemyPrev = xEnemy;

                            xEnemy-=lEnemy;

                        }




                        //deteksi buah dimakan hero

                        if((xHero==xFruit)&&(yHero ==yFruit))
                        {

                            score++;
                            insert(i);
                           gotoxy(xScore,yScore);cout<<score;
                            display();
                            if(score>=5)
                            {
                                gotoxy(10,10);cout << "selamat anda memenanglan game ini";
                                displayHistory();

                                 char pilihan;


                             gotoxy(76,22);cout<<"Coba Lagi (y/t)"<<endl;
                             gotoxy(77,23);cin>>pilihan;
                             if(pilihan=='y')
                             {
                               score = 0;
                                nyawaPlayer=0;

                                resetHistory(); // menghapus tulisan nama inputan user
                                hapusReset(); // menghapus skor yang sudah di cetak
                                levelPlayer++;


                                system("cls");
                                goto menang;
                             }
                             if(pilihan=='t')
                             {

                                 score = 0;

                                 nyawaPlayer=0;
                                hapusReset();
                                kolom++;
                                baris = 85;



                                 break;
                             }
                                break;

                            }


                            hapus(i);
                            xScore--;


                            xFruit =acakX();
                            yFruit = acakY();
                            gotoxy(xFruit,yFruit);

                            cout << "*";
                            cariDetik=0;
                        }

                         if(((int)xEnemy==xFruit)&&((int)yEnemy==yFruit))
                         {

                            xFruit = acakX();
                            yFruit = acakY();
                            gotoxy(xFruit,yFruit);cout << "*";
                         }

                         //terkena musuh terdapat pelanggaran bila sudah lebih dari 3  maka gagal
                         if((xHero==(int)xEnemy)&&(yHero==(int)yEnemy))
                         {


                            gotoxy(75,7);cout<<nyawaPlayer;
                            nyawaPlayer++;
                            xHero = acakX();
                            yHero = acakY();
                            gotoxy(75,7);cout<<nyawaPlayer;

                            if(nyawaPlayer == 3)
                            {
                                        char pilihan;


                                     gotoxy(76,22);cout<<"Coba Lagi (y/t)"<<endl;
                                     gotoxy(77,23);cin>>pilihan;
                                     if(pilihan=='y')
                                     {
                                        score = 0;
                                        nyawaPlayer =0;

                                        resetHistory();
                                        hapusReset();
                                        system("cls");
                                        goto reset;
                                     }
                                      if(pilihan=='t')
                                     {
                                         score = 0;
                                         nyawaPlayer=0;
                                        hapusReset();
                                        kolom++;
                                        baris = 85;

                                         break;
                                     }
                                     break;

                            }



                         }
                       slow();


                    } while (key != 27);

system("cls");
}

void menuGameMultiplayer()
{

    system("cls");
    bingkaiAtasGame();
    bingkaiSampingGame();
    int pilih;

    gotoxy(40,11);
    cout << "1.GAME KEJAR MONSTER";
    gotoxy(40,13);
    cout << "2.GAME BALAPAN";
    gotoxy(40,15);
    cout <<"Masukan Pilihan Anda...";
    gotoxy(40,16);
    cin>>pilih;

    switch(pilih)
    {
        case 1 :
        {
            gameMultiplayer();
            break;
        }
        case 2 :
        {
            gameMultiplayerBalapan();
            break;
        }
    }

}


void menuGame()
{
    int pilih;

    gotoxy(40,5);
    cout<<"PILIH MENU YANG AKAN DI TUJU";
    gotoxy(40,7);
    cout<<"1. SOLO";
    gotoxy(40,9);
    cout<< "2. RANK";
    gotoxy(40,11);
    cout<<"3. MULTIPLAYER";
    gotoxy(40,13);
    cout<<"4. EXIT";

    gotoxy(40,15);
    cout<< "Masukan Pilihan Anda.....";
    gotoxy(40,16);
    cin>>pilih;

     switch(pilih)
   {
case 1:
    {
        game();
        break;
    }
case 2:
    {
        gameRanked();
        break;
    }
case 3:
    {
        menuGameMultiplayer();
        break;
    }
case 4 :
    {
        exit(0);
    }

   }

}

//fungsi main

int main()
{
    int main = 1;


    do
    {

        opening();
        ulang :
         bingkaiAtasGame();
         bingkaiSampingGame();
         menuGame();
         goto ulang;
        //skor game
        //perhitunganSkor();
        //cin>>cobaNama;
        //perhitunganSkor();


          //opening();

        main++;
    }while(main !=2);



    return 0;
}
