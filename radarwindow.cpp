#include "radarwindow.h"
#include "ui_radarwindow.h"

RadarWindow::RadarWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RadarWindow),
    m_toolbarVis(true),
    m_centerSelect(false)
{
    ui->setupUi(this);

    setMenus();

    m_radarView = new RadarView(this->width(), this->height(), ui->centralWidget);
    m_radarScene = new RadarScene(m_radarView->width(), m_radarView->height(), m_radarView);
    m_radarView->setScene(m_radarScene);

    m_borderUA = new Border(":/cfg/border.pt", MapObject::Deg, m_radarScene);
    m_tma = new Sector(":/cfg/tma.pt", MapObject::DegMinSec, m_radarScene);
    m_tma->SetActive(true);

    setPoints(":/cfg/list.pt");

    m_radarScene->AddMapObj(m_borderUA);
    m_radarScene->AddMapObj(m_tma);

    m_target = new Target(m_radarScene);
    m_radarScene->AddMapObj(m_target);

    m_radarScene->Scale(ui->scaleSlider->value() * SCALE_FACTOR); // scale only when all visual data loaded!!!

    connect(ui->toolbarOpenBtn, &QPushButton::clicked, this, &RadarWindow::toolbarVis);
    connect(ui->scaleSlider, &QSlider::valueChanged, this, &RadarWindow::scaleChange);
    connect(ui->centerSeclectBtn, &QPushButton::clicked, this, &RadarWindow::centerSelect);
    connect(ui->ownSectorSwitcher, &QCheckBox::stateChanged, this, &RadarWindow::sectorFill);

}

RadarWindow::~RadarWindow()
{
    delete ui;
}

void RadarWindow::setMenus()
{
    ui->scaleLabel->setText(QString::number(ui->scaleSlider->value()));

}

void RadarWindow::setPoints(QString filename)
{
    QFile file(filename);
    QStringList file_lines;
    QString file_line;


    file.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!file.atEnd())
    {
        file_line = file.readLine();
        file_lines = file_line.split(':');

        m_points.insert(file_lines.at(0), new Point(m_radarScene, file_lines.at(0)));
        m_points.value(file_lines.at(0))->SetPos(file_lines.at(1));
        m_radarScene->AddMapObj(m_points.value(file_lines.at(0)));
    }
    file.close();

}

void RadarWindow::mousePressEvent(QMouseEvent *event)
{
    switch (event->button())
    {
        case Qt::LeftButton :
        {
            if(m_centerSelect)
            {
                QPoint point(event->pos());
                m_radarScene->SetCenter(m_radarView->mapToScene(point), ui->scaleSlider->value() * SCALE_FACTOR);

                m_centerSelect = false;
                m_radarView->setCursor(QCursor(Qt::ArrowCursor));
            }
            break;
        }
        default:
            break;
    };
}

void RadarWindow::toolbarVis()
{
    if(ui->toolBar->isHidden())
    {
        m_toolbarVis = true;
        ui->toolBar->setVisible(m_toolbarVis);
    }
    else
    {
        m_toolbarVis = false;
        ui->toolBar->setVisible(m_toolbarVis);
    }
}

void RadarWindow::scaleChange(int value)
{
    ui->scaleLabel->setText(QString::number(value));
    m_radarScene->Scale(value * SCALE_FACTOR);
}

void RadarWindow::centerSelect()
{
    m_centerSelect = true;
    QCursor::setPos(m_radarView->width()/2, m_radarView->height()/2);
}

void RadarWindow::sectorFill(int val)
{
    m_tma->SetActive(val);
}
