#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "versioninfo.h"
#include <QtGui>            //Per QPoint
#include <QMessageBox>      //Per Messaggi di alert

/*HS************Costruttore della LoginWindow********************************
* Il costruttore costruisce la MainWindows con i parametri FramelessWindowsHint e WindowSystemMenuHint
* che permettono di rendere "bordless" la finestra. Avrei potuto abilitare la proprietà della
* QMainWindow anzichè buttare sangue dagli occhi per capire come farlo da codice sorgente
*****************************************************************************/
LoginWindow::LoginWindow(QWidget *parent):
    QMainWindow(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint), ui(new Ui::LoginWindow){
    ui->setupUi(this);
    //Associo alla QLabel "version" la stringa "qstr". In questo modo vedo sulla schermata la versione del software in uso
    ui->version->setText(qstr);
    //Associo l'immagine di sfondo al frame (parte dal punto 0x0, dimensioni 390x670)
    frame->setGeometry(0,0, 390,670);
    frame->setStyleSheet("background-image: url(:/image/SfondoTotal.png)");
}

/*HS************Distruttore della LoginWindow********************************
 * Distruggo il frame e l'user interface
 ***************************************************************************/
LoginWindow::~LoginWindow(){
    delete frame;
    delete ui;
}

/*HS*************************************************************************
* Questa funzione viene richiamata quando clicchiamo il pulsante "X" per uscire dal programma
*****************************************************************************/
void LoginWindow::on_exitButton_clicked(){
    QApplication::quit(); //TODO: Il programma finisce "male"?
}

/*HS*************************************************************************
* Questa funzione acquisisce la posizione x-y del mouse quando viene pressato il bottone sinistro
* sulla finestra LoginWindow e salva tale posizione nella variabile "oldPos" di tipo QPoint.
*
* La funzione va in coppia con la seguente LoginWindow::mouseMoveEvent che permette il trascinamento
* della finestra
*****************************************************************************/
void LoginWindow::mousePressEvent(QMouseEvent *evt){
     oldPos = evt->globalPos();
}

/*HS*************************************************************************
* Questa funzione permette di trascinare la finestra LoginWindow quando si preme il pulsante sinistro
* del mouse sulla finestra LoginWindow, ricalcolandone la posizione x-y.
* Il ricalcolo della finestra tramite l'ausilio di un altro punto QPoint chiamato "delta" a cui viene
* sottratta la vecchia posizione aquisita del mouse tramite la funzione precedente, ossia la funzione
* LoginWindow::mousePressEvent (vedi descrizione approfondita alla fine di questo commento).
*
* Il riposizionamento della finestra avviene con la funzione "move". A questa funzione vengono passati:
* 1) la vecchia coordinata x a cui viene sommato il delta-x dello spostamento lungo l'asse x
* 2) la vecchia coordinata y a cui viene sommato il delta-y dello spostamento lungo l'asse y
*
* Infine, la funzione riacquisisce la posizione x-y del mouse, in modo che al frame video successivo si
* possa continuare a spostare la finestra, dando all'utente una percezione di continuità nel trascinamento
*
* La funzione va in coppia con la precedente LoginWindow::mousePressEvent che registra la posizione
* originale del mouse, memorizzando le coordinate x-y al momento della prima pressione del tasto sinistro
* sulla finestra
*****************************************************************************/
void LoginWindow::mouseMoveEvent(QMouseEvent *evt){
    const QPoint delta = evt->globalPos() - oldPos;
    move(x()+delta.x(), y()+delta.y());
    oldPos = evt->globalPos();
}

/*HS*************************************************************************
* Evento che si verifica alla pressione del bottone "LoginButton".
* La funzione va a settare uno StyleSheet diverso quando il bottone va tenuto premuto
*****************************************************************************/
void LoginWindow::on_LoginButton_pressed(){
    ui->LoginButton->setStyleSheet("QPushButton:pressed { color: rgb(255, 255, 255); background-color: rgb(28, 110, 164); font-size: 16px; border-radius: 20px; border: 3px solid rgb(28, 110, 164);}");
}

/*HS*************************************************************************
* Evento che si verifica al rilascio del bottone "LoginButton".
* La funzione riporta lo StyleSheet del bottone ai suoi valori originali
*****************************************************************************/
void LoginWindow::on_LoginButton_released(){
    ui->LoginButton->setStyleSheet("QPushButton { color: rgb(255, 255, 255); background-color: rgb(20, 115, 255); font-size: 16px; border-radius: 20px; border: 3px solid rgb(28, 110, 164);}");
}

/*HS**************************************************************************
* Probabilmente non la implementeremo
******************************************************************************/
void LoginWindow::on_ForgotPasswordButton_clicked(){
    QMessageBox msgBox;
    msgBox.setText("Funzione non implementata");
    msgBox.exec();
}