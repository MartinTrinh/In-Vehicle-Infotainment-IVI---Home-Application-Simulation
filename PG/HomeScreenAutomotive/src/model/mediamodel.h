#ifndef MEDIAMODEL_H
#define MEDIAMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QScopedPointer>

QT_BEGIN_NAMESPACE
class QMediaPlaylist;
QT_END_NAMESPACE

class Song
{
public:
    Song(const QString &title, const QString &singer, const QString &source, const QString &albumArt);

    QString title() const;
    QString singer() const;
    QString source() const;
    QString album_art() const;

private:
    QString m_title;
    QString m_singer;
    QString m_source;
    QString m_albumArt;
};
class MediaModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MediaModel(QObject *parent = nullptr);
    enum Roles {
        TitleRole = Qt::UserRole + 1,
        SingerRole,
        SourceRole,
        AlbumArtRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    //QModelIndex index(int row, int column = 0, const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    //QModelIndex getIndex(int row) const;

    void addSong(Song &song);
protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QList<Song> m_data;

};

#endif // MEDIAMODEL_H
