#include "inspector.h"
#include "transform.h"

#include <QLayout>
#include <QBoxLayout>
#include <QSpacerItem>
#include <QLineEdit>
#include <QPushButton>

Inspector::Inspector(QWidget *parent) :
    QWidget(parent)
{

    //Subwidgets --> Add transform and others
    name = new QLineEdit();
    QSpacerItem* spacer = new QSpacerItem(1,1,QSizePolicy::Expanding,QSizePolicy::Expanding);
    transform = new Transform();



    //Set the layout
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(name);
    layout->addWidget(transform);
    layout->addItem(spacer);
    setLayout(layout);


    //Slot connections
    connect(name,SIGNAL(textEdited(QString)),this, SLOT(TextChanged(QString)));

}

Inspector::~Inspector()
{
}

void Inspector::TextChanged(QString new_name)
{
    name->setText("This has changed");
}
