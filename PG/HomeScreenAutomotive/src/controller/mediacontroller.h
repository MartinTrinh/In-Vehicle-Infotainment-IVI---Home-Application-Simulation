#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/id3v2tag.h>
#include <taglib/mpegfile.h>
#include <taglib/id3v2frame.h>
#include <taglib/id3v2header.h>
#include <taglib/attachedpictureframe.h>
#include "mediamodel.h"

QT_BEGIN_NAMESPACE
class QAbstractItemView;
class QMediaPlayer;
QT_END_NAMESPACE

class PlaylistModel;

using namespace TagLib;

class MediaController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 duarationTotal READ getDuarationTotal  NOTIFY duarationChanged)
    Q_PROPERTY(qint64  currentDuaration READ getCurrentDuaration  NOTIFY currentTimeChanged)
    Q_PROPERTY(QString totalTime  READ getTotalTime NOTIFY duarationChanged)
    Q_PROPERTY(QString  currentTime READ  getCurrentTime  NOTIFY currentTimeChanged)
    Q_PROPERTY(qint32 volume READ getVolume NOTIFY volumeChanged)
public:
    explicit MediaController(QObject *parent = nullptr);
    ~MediaController();
    // singleton pattern
    static MediaController *getInstance();

    // initialize controller
    void initialize(QQmlContext *context);

    void addToPlaylist(const QList<QUrl> &urls);
    void open();
    QString getAlbumArt(QUrl url);
    void initPlayListMediaPlayer();
    QMediaPlaylist* getMediaPlaylist();
    QMediaPlayer* getMediaPlayer();
    MediaModel * getModel();

    //get infomation of the list song to QML view
    QString getTotalTime() const;
    QString getCurrentTime() const;
    qint64 getDuarationTotal() const;
    qint64 getCurrentDuaration() const;
    Q_INVOKABLE QString getSongName() const;
    Q_INVOKABLE QString getSinger() const;

    //function controller
    Q_INVOKABLE void continuePlayer();
    Q_INVOKABLE void initPlayer();
    Q_INVOKABLE void pausePlayer();
    Q_INVOKABLE void setPosition(qint64 position);
    Q_INVOKABLE void setCurrenIndex(int index);
    Q_INVOKABLE bool checkPlayerState();

    Q_INVOKABLE void setVolume(qint32 volume );
    Q_INVOKABLE qint32 getVolume() const;

    Q_INVOKABLE void next();
    Q_INVOKABLE void previous();
    Q_INVOKABLE void switchModePlaylist(int mode = QMediaPlaylist::Sequential);
public slots:
    void onMetaDataAvailableChanged(bool available);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
#if __linux
    void onMetaDataChanged(const QString &key, const QVariant &value);
#elif defined(_WIN32) || defined(_WIN64)
    void onMetaDataChanged();
#endif

signals:
    void duarationChanged();
    void currentTimeChanged();
    void currentIndexChanged();
    void volumeChanged();
private:
    QMediaPlayer *m_player ;
    QMediaPlaylist *m_playlist ;
    MediaModel *m_playlistModel;
    qint64 m_duarationTotal;
    QString m_totalTime;
    QString m_currentTime;
    qint64 m_currentDuaration;
    qint32 m_initVolume;
    QString m_songName;
    QString m_singer;
    qint32 m_volume;

    static MediaController *m_instance;
    bool m_initialized;
    QQmlApplicationEngine *m_engine;
};

#endif // MEDIACONTROLLER_H
