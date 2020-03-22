// Copyright (c) 2017-2020 The INDIANCOIN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZINDCONTROLDIALOG_H
#define ZINDCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zind/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZIndControlDialog;
}

class CZIndControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZIndControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZIndControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZIndControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZIndControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZIndControlDialog(QWidget *parent);
    ~ZIndControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZIndControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZIndControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZINDCONTROLDIALOG_H
