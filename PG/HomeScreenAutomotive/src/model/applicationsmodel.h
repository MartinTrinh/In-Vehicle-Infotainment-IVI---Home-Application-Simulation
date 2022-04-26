#ifndef APPLICATIONSMODEL_H
#define APPLICATIONSMODEL_H
#include <QAbstractListModel>

class ApplicationItem {
public:
    ApplicationItem(QString title, QString url, QString iconPath);
    QString title() const;
    QString url() const;
    QString iconPath() const;
private:
    QString m_title;
    QString m_url; // into a screen
    QString m_iconPath;// contain image of icon

};

class ApplicationsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        TitleRole = Qt::UserRole + 1,
        UrlRole,
        IconPathRole
    };
    explicit ApplicationsModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void addApplication(ApplicationItem &item);
    void moveItem(int from, int to);
    QList<ApplicationItem> getListApp();
protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<ApplicationItem> m_data;
};

#endif // APPLICATIONSMODEL_H
