// Copyright (c) 2019 The INDIANCOIN developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLINDWIDGET_H
#define COINCONTROLINDWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlIndWidget;
}

class CoinControlIndWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlIndWidget(QWidget *parent = nullptr);
    ~CoinControlIndWidget();

private:
    Ui::CoinControlIndWidget *ui;
};

#endif // COINCONTROLINDWIDGET_H
