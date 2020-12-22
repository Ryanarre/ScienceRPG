#include "ImageManager.h"

#include <QImageReader>

ImageManager::ImageManager() {}

bool ImageManager::setImage(QString const & path, QLabel * label)
{
    QImageReader reader(path);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull())
        return false;

    QPixmap pixmap = QPixmap::fromImage(newImage);
    label->setAlignment (Qt::AlignCenter);
    label->setPixmap(pixmap.scaled(label->width(), label->height(), Qt::KeepAspectRatio));
    return true;
}
