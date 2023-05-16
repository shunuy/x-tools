/******************************************************************************
 * Copyright 2023 Qsaker(wuuhaii@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 *****************************************************************************/
#ifndef SAKSOCKETSERVERTOOLUI_H
#define SAKSOCKETSERVERTOOLUI_H

#include "SAKCommunicationToolUi.hh"

namespace Ui {
class SAKSocketServerToolUi;
}
class SAKSocketServerToolUi : public SAKCommunicationToolUi
{
    Q_OBJECT
public:
    explicit SAKSocketServerToolUi(QWidget *parent = nullptr);
    ~SAKSocketServerToolUi();
    virtual void setupCommunicationTool(SAKCommunicationTool *tool) final;
    virtual void updateUiState(bool isWorking) final;

private:
    Ui::SAKSocketServerToolUi *ui{nullptr};
};

#endif // SAKSOCKETSERVERTOOLUI_H