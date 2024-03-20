/***************************************************************************************************
 * Copyright 2023-2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include <QIcon>
#include <QList>
#include <QLoggingCategory>
#include <QTimer>
#include <QWidget>

#include "sakcommunicationtoolui.h"
#include "xToolsToolBox.h"

namespace Ui {
class xToolsToolBoxUi;
}

class SAKEmitterToolUi;
class SAKResponserToolUi;
class SAKPrestorerToolUi;
class xToolsCommunicationTool;
class xToolsToolBoxUiInputMenu;
class xToolsToolBoxUiOutputMenu;
class SAKCommunicationToolUi;
class SAKTcpTransmitterToolUi;
class SAKUdpTransmitterToolUi;
class xToolsToolBoxUiCommunicationMenu;
class xToolsWebSocketTransmitterToolUi;
class SAKSerialPortTransmitterToolUi;
class xToolsToolBoxUi : public QWidget
{
    Q_OBJECT
public:
    explicit xToolsToolBoxUi(QWidget *parent = nullptr);
    ~xToolsToolBoxUi() override;

    static QList<int> supportedCommunicationTools();
    static QString communicationToolName(int type);
    static QIcon communicationToolIcon(int type);

    void initialize(int type);

private:
    xToolsToolBox *m_toolBox{nullptr};
    xToolsCommunicationTool *m_communication{nullptr};
    SAKCommunicationToolUi *m_communicationUi{nullptr};
    SAKEmitterToolUi *m_emitterUi{nullptr};
    SAKResponserToolUi *m_responserUi{nullptr};
    SAKPrestorerToolUi *m_prestorerUi{nullptr};
    SAKTcpTransmitterToolUi *m_tcpTransmitterUi{nullptr};
    SAKUdpTransmitterToolUi *m_udpTransmitterUi{nullptr};
    xToolsWebSocketTransmitterToolUi *m_webSocketTransmitterUi{nullptr};
    SAKSerialPortTransmitterToolUi *m_serialPortTransmitterUi{nullptr};
    QTimer *m_cycleSendingTimer{nullptr};
    int m_communicationType;
    xToolsToolBoxUiCommunicationMenu *m_communicationMenu{nullptr};
    xToolsToolBoxUiInputMenu *m_inputMenu{nullptr};
    xToolsToolBoxUiOutputMenu *m_outputMenu{nullptr};

    struct
    {
        QString tabIndex;
        QString items;
        QString transmitterTabIndex;
    } m_settingsKey;

private:
    SAKCommunicationToolUi *communicationToolUi(int type);
    void try2send();
    QString dateTimeFormat();
    void output2ui(const QByteArray &bytes, const QString &flag, bool isRx);
    QString settingsGroup();
    QByteArray calculateCrc(const QByteArray &bytes = QByteArray(), bool fixedOriginOrder = false);
    void setDefaultText();

private slots:
    void onIsWorkingChanged();
    void onBytesWritten(const QByteArray &bytes, const QString &from);
    void onBytesRead(const QByteArray &bytes, const QString &to);
    void onInputTextChanged();

private:
    void init();

    void initUi();
    void initUiCommunication();
    void initUiInput();
    void initUiOutput();

    void initSettings();
    void initSettingsCommunication();
    void initSettingsInput();
    void initSettingsOutput();

    void initSignals();
    void initSignalsCommunication();
    void initSignalsInput();
    void initSignalsOutput();

    void initTools();

private:
    Ui::xToolsToolBoxUi *ui;
    void onTabWidgetCurrentChanged(int index);

    // communication
    void onPushButtonCommunicationOpenClicked();

    // input
    void onPushButtonInputSendClicked();
    void onComboBoxInputIntervalActivated();
    void onComboBoxInputFormatActivated();
    void onComboBoxInputTextActivated();

    // output
    void onCheckBoxOutputWrapClicked();
};