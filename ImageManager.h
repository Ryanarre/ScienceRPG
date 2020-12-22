#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H

#include <QLabel>

class ImageManager
{
public:
    ImageManager();

    bool setImage(QString const & path, QLabel * label);
};

#endif // IMAGEMANAGER_H
