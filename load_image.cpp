#include "load_image.h"
#include <QLabel>
load_image::load_image()
{

}
void load_image::load_field(MainWindow * w , string path){

    QPixmap pic(path.c_str());



    QLabel *label = new QLabel(w);
    label->setGeometry(QRect(0, 0, pic.width(), pic.height()));
    label->setPixmap(pic);

}
