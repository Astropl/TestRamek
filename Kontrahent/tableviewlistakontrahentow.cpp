#include "tableviewlistakontrahentow.h"
#include <QAbstractTableModel>

TableViewListaKontrahentow::TableViewListaKontrahentow(QObject *parent)
:QAbstractTableModel(parent)
{

}
int TableViewListaKontrahentow::rowCount(const QModelIndex & /*parent*/) const
{
   return 10;
}

int TableViewListaKontrahentow::columnCount(const QModelIndex & /*parent*/) const
{
    return 30;
}

QVariant TableViewListaKontrahentow::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
       return QString("Row%1, Column%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);
    }
    return QVariant();
}
