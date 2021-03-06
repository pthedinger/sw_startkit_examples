/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QGroupBox;
class QLabel;
class QDial;
class QStackedWidget;
class QPushButton;
class BiquadControls;
class QSpinBox;
QT_END_NAMESPACE

#define MAX_COMMAND_LEN 100

extern int g_sockfd;

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

public slots:
    void enableBiquads(bool enable);
    void enableDrc(bool enable);

    void setPreGain(int value);
    void setGain(int value);

    void setBiquadBank(int index, int value);
    void setLevelAttack(int value);
    void setLevelRelease(int value);
    void setLevelThreshold(int value);

private:
    void createBiquadControls();
    void createDrcControls();
    void createControls();

    QStackedWidget *m_stackedWidget;

    // BIQUADS
    QGroupBox *m_biquadControlBox;
    BiquadControls *m_biquadSliders;
    QCheckBox *m_biquadEnable;
    QPushButton *m_selectAll;
    QPushButton *m_selectNone;
    QPushButton *m_selectInvert;

    // DRC
    QGroupBox *m_drcControlBox;
    QCheckBox *m_drcEnable;

    // GAIN
    QGroupBox *m_preGainBox;
    QDial *m_preGainDial;
    QSpinBox *m_preGainSpinBox;

    QGroupBox *m_gainBox;
    QDial *m_gainDial;
    QSpinBox *m_gainSpinBox;
};

#endif
