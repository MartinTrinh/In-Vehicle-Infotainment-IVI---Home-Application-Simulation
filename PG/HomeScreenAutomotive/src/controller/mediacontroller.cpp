#include "mediacontroller.h"
#include "loghelper.h"
#include <QMediaMetaData>
#include <QMediaService>
#include <QMediaPlaylist>
#include <QMediaMetaData>
#include <QFileInfo>
#include <QTime>
#include <QDir>
#include <QStandardPaths>
#include<iostream>
#include<cstdlib>

MediaController *MediaController::m_instance = nullptr;

MediaController::MediaController(QObject *parent) : QObject(parent)
{
    LOG_INFO << "START";
    m_totalTime = "00:00";
    m_duarationTotal = 0;
    m_currentTime = "00:00";
    m_currentDuaration = 0;
    m_initVolume = 40;
    m_songName = "...";
    m_singer = "...";
    m_player = new QMediaPlayer(this);
    m_playlist = new QMediaPlaylist(this);
    m_playlistModel = new MediaModel(this);
    m_initialized = false;
    open();
    initPlayListMediaPlayer();
    //#if __linux
    //    QObject::connect(m_player, SIGNAL(metaDataChanged(QString&, QVariant&)),  this, SLOT(onMetaDataChanged(QString&,QVariant&)));
    //#elif defined(_WIN32) || defined(_WIN64)
    //    QObject::connect(m_player, SIGNAL(metaDataChanged()),this, SLOT(onMetaDataChanged()));
    //#endif

    QObject::connect(m_player,&QMediaPlayer::metaDataAvailableChanged, this, &MediaController::onMetaDataAvailableChanged);
    QObject::connect(m_player, &QMediaPlayer::positionChanged, this , &MediaController::onPositionChanged);
    QObject::connect(m_player, &QMediaPlayer::durationChanged, this , &MediaController::onDurationChanged);
    LOG_INFO << "END";
}

MediaController::~MediaController()
{
    LOG_INFO << "START";
    m_player = nullptr;
    m_playlist = nullptr;
    m_playlistModel = nullptr;
    LOG_INFO << "END";
}

MediaController *MediaController::getInstance()
{
    if(m_instance ==nullptr)
    {
        m_instance = new MediaController();
    }
    return m_instance;
}

void MediaController::initialize(QQmlContext *context)
{
    LOG_INFO << "START";
    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        context->setContextProperty("MEDIA_CTRL", this); // media controller
        context->setContextProperty("MEDIA_MODEL",m_playlistModel); // model form c++
        context->setContextProperty("PLAYER",m_player);
        context->setContextProperty("PLAYLIST",m_playlist);
    }
    LOG_INFO << "END";
}

void MediaController::addToPlaylist(const QList<QUrl> &urls)
{
    LOG_INFO << "START";
    for (auto &url: urls) {
        FileRef f(url.path().toStdString().c_str());
        Tag *tag = f.tag();
        Song song(QString::fromWCharArray(tag->title().toCWString()),
                  QString::fromWCharArray(tag->artist().toCWString()),url.toDisplayString(),
                  getAlbumArt(url));
        m_playlistModel->addSong(song); // add to model of playlist song
        m_playlist->addMedia(url); // add to playlist of QMediaPlaylist
    }
    LOG_INFO << "END";
}

void MediaController::open()
{
    LOG_INFO << "START";
    QDir directory(QStandardPaths::standardLocations(QStandardPaths::MusicLocation)[0]);
    QFileInfoList musics = directory.entryInfoList(QStringList() << "*.mp3",QDir::Files);
    QList<QUrl> urls;
    for (int i = 0; i < musics.length(); i++){
        urls.append(QUrl::fromLocalFile(musics[i].absoluteFilePath()));
        // LOG_INFO << musics[i].absoluteFilePath();
    }
    addToPlaylist(urls);
    LOG_INFO << "END";
}

QString MediaController::getAlbumArt(QUrl url)
{
    LOG_INFO << "START";
    static const char *IdPicture = "APIC" ;
    TagLib::MPEG::File mpegFile(url.path().toStdString().c_str());
    TagLib::ID3v2::Tag *id3v2tag = mpegFile.ID3v2Tag();
    TagLib::ID3v2::FrameList Frame ;
    TagLib::ID3v2::AttachedPictureFrame *PicFrame ;
    void *SrcImage ;
    unsigned long Size ;

    FILE *jpegFile;
    jpegFile = fopen(QString(url.fileName()+".jpg").toStdString().c_str(),"wb");

    if ( id3v2tag )
    {
        // picture frame
        Frame = id3v2tag->frameListMap()[IdPicture] ;
        if (!Frame.isEmpty() )
        {
            for(TagLib::ID3v2::FrameList::ConstIterator it = Frame.begin(); it != Frame.end(); ++it)
            {
                PicFrame = static_cast<TagLib::ID3v2::AttachedPictureFrame*>(*it) ;
                if ( PicFrame->type() == TagLib::ID3v2::AttachedPictureFrame::FrontCover)
                {
                    // extract image (in it’s compressed form)
                    Size = PicFrame->picture().size() ;
                    SrcImage = malloc ( Size ) ;
                    if ( SrcImage )
                    {
                        memcpy ( SrcImage, PicFrame->picture().data(), Size ) ;
                        fwrite(SrcImage,Size,1, jpegFile);
                        fclose(jpegFile);
                        free( SrcImage ) ;
                        return QUrl::fromLocalFile(url.fileName()+".jpg").toDisplayString();
                    }
                }
            }
        }
    }
    else
    {
        LOG_INFO <<"id3v2 not present";
        return "qrc:/Image/album_art.png";
    }
    LOG_INFO << "END";
    return "qrc:/Image/album_art.png";
}

void MediaController::initPlayListMediaPlayer()
{
    LOG_INFO << "START";
    if(!m_playlist->isEmpty())
    {
        m_player->setPlaylist(m_playlist);
        m_player->setVolume(20);
        m_playlist->setCurrentIndex(0);
    }else{
        LOG_INFO << "THE PLAYLIST IS EMPTY !!!!";
    }
    LOG_INFO << "END";
}

QMediaPlaylist *MediaController::getMediaPlaylist()
{
    return m_playlist;
}

QMediaPlayer *MediaController::getMediaPlayer()
{
    return m_player;
}

MediaModel *MediaController::getModel()
{
    return m_playlistModel;
}

QString MediaController::getTotalTime() const
{
    return m_totalTime;
}

QString MediaController::getCurrentTime() const
{
    return m_currentTime;
}

qint64 MediaController::getDuarationTotal() const
{
    return m_duarationTotal;
}

qint64 MediaController::getCurrentDuaration() const
{
    return m_currentDuaration;
}

QString MediaController::getSongName() const
{
    return m_songName;
}

QString MediaController::getSinger() const
{
    return m_singer;
}

void MediaController::continuePlayer()
{
    m_player->play();
}

void MediaController::initPlayer()
{
    LOG_INFO << "START";
    if(!m_player->playlist()->isEmpty())
    {
        m_player->play();
        m_player->setVolume(m_initVolume);
    }else{
        LOG_INFO << "THE PLAYLIST IS EMPTY !!!!";
    }
    LOG_INFO << "END";
}

void MediaController::pausePlayer()
{
    m_player->pause();
}

void MediaController::setPosition(qint64 position)
{
    m_player->setPosition(position*1000);
}

void MediaController::setCurrenIndex(int index)
{
    if(index > m_player->playlist()->mediaCount())
    {
        m_player->playlist()->setCurrentIndex(0);
    }else
    {
        m_player->playlist()->setCurrentIndex(index);
    }
}

bool MediaController::checkPlayerState()
{
    if(m_player->state() == QMediaPlayer::PlayingState)
    {
        return true;

    }else if(m_player->state() == QMediaPlayer::PausedState || m_player->state() == QMediaPlayer::StoppedState ){
        return false;
    }
    return false;
}

//void MediaController::setVolume(qint32 volume)
//{
//    m_volume = volume;
//    m_player->setVolume(m_volume);
//    emit volumeChanged();
//}

qint32 MediaController::getVolume() const
{
    return m_player->volume();
}

void MediaController::next()
{
    LOG_INFO << "START";
    if(m_player->playlist()->currentIndex() == m_player->playlist()->mediaCount() - 1 ){
        m_player->playlist()->setCurrentIndex(0);
    }else{
        //        if(m_player->playlist()->playbackMode() == QMediaPlaylist::CurrentItemInLoop){
        //            m_player->playlist()->setCurrentIndex(m_player->playlist()->currentIndex() + 1);
        //        }else if(m_player->playlist()->playbackMode() == QMediaPlaylist::Random)
        //        {
        //            srand(time(0));
        //            m_player->playlist()->setCurrentIndex(rand() % m_player->playlist()->mediaCount());
        //        }else {
        m_player->playlist()->next();
        //        }
    }
    LOG_INFO << "END";

}

void MediaController::previous()
{
    LOG_INFO << "START";
    if(m_player->playlist()->currentIndex() == 0 ){
        m_player->playlist()->setCurrentIndex(m_player->playlist()->mediaCount() - 1);
    }else{
        if(m_player->playlist()->playbackMode() == QMediaPlaylist::CurrentItemInLoop){
            m_player->playlist()->setCurrentIndex(m_player->playlist()->currentIndex() - 1);
        }else if(m_player->playlist()->playbackMode() == QMediaPlaylist::Random)
        {
            srand(time(0));
            m_player->playlist()->setCurrentIndex(rand() % m_player->playlist()->mediaCount());
        }else {
            m_player->playlist()->previous();
        }
    }
    LOG_INFO << "END";
}

void MediaController::switchModePlaylist(int mode)
{
    LOG_INFO << "START";
    switch(mode)
    {
    case QMediaPlaylist::CurrentItemOnce:
        m_player->playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
        LOG_INFO << "CurrentItemOnce";
        break;
    case QMediaPlaylist::CurrentItemInLoop:
        m_player->playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        LOG_INFO << "CurrentItemInLoop";
        break;
    case QMediaPlaylist::Random:
        m_player->playlist()->setPlaybackMode(QMediaPlaylist::Random);
        LOG_INFO << "RANDOM";
        break;
    case QMediaPlaylist::Loop:
        m_player->playlist()->setPlaybackMode(QMediaPlaylist::Loop);
        LOG_INFO << "LOOP";
        break;
    default:
        m_player->playlist()->setPlaybackMode(QMediaPlaylist::Sequential);
        LOG_INFO << "Sequential";
        break;
    }
    LOG_INFO << "END";
}

void MediaController::onMetaDataAvailableChanged(bool available)
{
    LOG_INFO << available;
    if(available)
    {
        emit currentIndexChanged();
    }
}

void MediaController::onDurationChanged(qint64 duration)
{
    //LOG_INFO << duration;
    qint64 durarionTotal =  duration / 1000;
    QTime totalTime((durarionTotal / 3600) % 60, (durarionTotal / 60) % 60,
                    durarionTotal % 60, (durarionTotal * 1000) % 1000);
    QString format = "mm:ss";
    m_totalTime = totalTime.toString(format); // for text
    m_duarationTotal = durarionTotal; // for processbar
    emit  duarationChanged();
}

void MediaController::onPositionChanged(qint64 position)
{
    LOG_INFO << position;
    qint64 visualPosition = position / 1000;
    QTime currentTime((visualPosition / 3600) % 60, (visualPosition / 60) % 60,
                      visualPosition % 60, (visualPosition * 1000) % 1000);
    QString format = "mm:ss";
    m_currentTime = currentTime.toString(format);
    m_currentDuaration = visualPosition;
    emit currentTimeChanged();
}

//#if __linux
//void MediaController::onMetaDataChanged(QString &key,QVariant &value)
//{
//    Q_UNUSED(key); // key of metaData
//    Q_UNUSED(value); // value of key
//    // using get data of media file( mp3, mp4,...)
//}
//#elif defined(_WIN32) || defined(_WIN64)
//void MediaController::onMetaDataChanged();
//{
//// using get data of media file( mp3, mp4,...)
//}
//#endif
