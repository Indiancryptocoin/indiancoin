// Copyright (c) 2019 The INDIANCOIN developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PRIVACYWIDGET_H
#define PRIVACYWIDGET_H

#include "qt/indiancoin/pwidget.h"
#include "qt/indiancoin/furabstractlistitemdelegate.h"
#include "qt/indiancoin/txviewholder.h"
#include "transactiontablemodel.h"
#include "transactionfilterproxy.h"
#include "coincontroldialog.h"

#include <QLabel>
#include <QWidget>

class INDIANCOINGUI;
class WalletModel;

namespace Ui {
class PrivacyWidget;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class PrivacyWidget : public PWidget
{
    Q_OBJECT

public:
    explicit PrivacyWidget(INDIANCOINGUI* parent);
    ~PrivacyWidget();

    void loadWalletModel() override;
private slots:
    void changeTheme(bool isLightTheme, QString &theme) override;
    void onCoinControlClicked();
    void onDenomClicked();
    void onRescanMintsClicked();
    void onResetZeroClicked();
    void onTotalZindClicked();
    void updateDisplayUnit();
    void showList();
    void onSendClicked();
    void onMintSelected(bool isMint);

private:
    Ui::PrivacyWidget *ui;
    FurAbstractListItemDelegate *delegate = nullptr;
    TransactionTableModel* txModel = nullptr;
    TxViewHolder *txHolder = nullptr;
    TransactionFilterProxy* filter = nullptr;
    CoinControlDialog *coinControlDialog = nullptr;

    int nDisplayUnit;
    void mint(CAmount value);
    void spend(CAmount value);
    void updateDenomsSupply();
};

#endif // PRIVACYWIDGET_H
