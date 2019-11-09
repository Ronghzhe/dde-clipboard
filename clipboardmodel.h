#ifndef CLIPBOARDMODEL_H
#define CLIPBOARDMODEL_H

#include <QAbstractListModel>
#include <QClipboard>
#include <QListView>

#include "itemdata.h"

class ClipboardModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ClipboardModel(QListView *list, QObject *parent = nullptr);

    // 清空所有剪贴板
    void clear();

    // 删除
    void removeItem(QModelIndex index);

    // 提取到第一个
    void extract(QModelIndex index);

    // all data
    const QList<ItemData *> data() const;

protected:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

public slots:
    void clipDataChanged();

private:
    QList<ItemData *> m_data;
    QClipboard *m_board;
    QListView *m_list;
};

#endif // CLIPBOARDMODEL_H