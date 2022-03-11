#include "userprofile.h"
#include "ui_userprofile.h"
#include <QMessageBox>
#include <QDebug>
#include <QTextCodec>

UserProfile::UserProfile(myClient* client, QString nome, QString mail,int files, int myFiles, QWidget *parent):
    QWidget(parent, Qt::FramelessWindowHint | Qt::WindowSystemMenuHint), ui(new Ui::UserProfile), _client(client) {

    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_DeleteOnClose, true); //Call the constructor when Windows close this.
    ui->setupUi(this);
    ui->Username->setText(nome); //Associate the QLabel "Username" at the string "nome" passed by argument. In this way I can show the username of the user
    ui->Mail->setText(mail);

    QString TotalFiles = QString::number(files);
    QString MyFiles = QString::number(myFiles);
    QString PartecipingFiles = QString::number(files-myFiles);

    ui->myFile->setText(MyFiles);
    ui->totFile->setText(TotalFiles);
    ui->otherFile->setText(PartecipingFiles);

    QChar firstLetter;

    for (int i=0;i<nome.length();i++){
        firstLetter = nome.at(i);
        if(firstLetter.isLetter()){
            break;
        }
    }

    QString color = _client->getColor();
    color[1]='f';
    color[2]='f';

    color = QString("#UserImageButton{"
            "border-radius: 18px;"
            "background:%1;"
            "color:white;"
            "}").arg(color);

    ui->UserImageButton->setStyleSheet(color);

    SimplifySingleCharForSorting(firstLetter,1);
    ui->UserImageButton->setText(firstLetter.toUpper());

    this->show();

}

UserProfile::~UserProfile() {
    emit closeUserProfile();
    delete ui;
}

//EXIT BUTTON
void UserProfile::on_exitButton_clicked() {
    QWidget::close();
    delete this;   //Needed to call destructor
}

//To make draggable the window
void UserProfile::mousePressEvent(QMouseEvent *evt) {
     oldPos = evt->globalPos();
}

//To make draggable the window
void UserProfile::mouseMoveEvent(QMouseEvent *evt) {
    const QPoint delta = evt->globalPos() - oldPos;
    move(x()+delta.x(), y()+delta.y());
    oldPos = evt->globalPos();
}

QChar UserProfile::SimplifySingleCharForSorting(QChar c, bool changeToLowerCase){

    if ( ( c >= QChar(0xC0) && c <= QChar(0xC5) ) || ( c >= QChar(0xE1) && c <= QChar(0xE5) ) || c == QChar(0xAA) )
        return ( ( c >= QChar(0xC0) && c <= QChar(0xC5) ) && !changeToLowerCase ) ? 'A' : 'a';

    if ( ( c >= QChar(0xC8) && c <= QChar(0xCB) ) || ( c >=QChar( 0xE8) && c <= QChar(0xEB) ) )
        return ( c > QChar(0xCB) || changeToLowerCase ) ? 'e' : 'E';

    if ( ( c >= QChar(0xCC) && c <= QChar(0xCF) ) || ( c >= QChar(0xEC) && c <= QChar(0xEF) ) )
        return ( c > QChar(0xCF) || changeToLowerCase ) ? 'i' : 'I';

    if ( ( c >=QChar(0xD2) && c <= QChar(0xD6) ) || ( c >= QChar(0xF2) && c <= QChar(0xF6) ) || c == QChar(0xBA) )
        return ( ( c >= QChar(0xD2) && c <= QChar(0xD6) ) && !changeToLowerCase ) ? 'O' : 'o';

    if ( ( c >= QChar(0xD9) && c <= QChar(0xDC) ) || ( c >= QChar(0xF9) && c <= QChar(0xFC) ) )
        return ( c > QChar(0xDC) || changeToLowerCase ) ? 'u' : 'U';

    if ( c == QChar(0xA9) || c == QChar(0xC7) || c == QChar(0xE7) )
        return ( c == QChar(0xC7) && !changeToLowerCase ) ? 'C' : 'c';

    if ( c ==QChar(0xD1) || c == QChar(0xF1) )
        return ( c == QChar(0xD1) && !changeToLowerCase ) ? 'N' : 'n';

    if ( c == QChar(0xAE) )
        return 'r';
    if ( c == QChar(0xDF) )
        return 's';
    if ( c == QChar(0x8E) || c == QChar(0x9E) )
        return ( c == QChar(0x8E) && !changeToLowerCase ) ? 'Z' : 'z';
    if ( c == QChar(0x9F) || c == QChar(0xDD) || c == QChar(0xFD) || c == QChar(0xFF) )
        return ( ( c == QChar(0x9F) || c == QChar(0xDD) ) && !changeToLowerCase ) ? 'Y' : 'y';
    return c;
}
