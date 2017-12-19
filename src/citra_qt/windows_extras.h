// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <QWidget>
class QWinThumbnailToolBar;
class QWinThumbnailToolButton;

class WindowsExtras : public QObject {
    Q_OBJECT

public:
    explicit WindowsExtras(QWidget* parent);
    ~WindowsExtras();

    void Show();
    void UpdatePlay();
    void UpdatePause();
    void UpdateStop();

private:
    void InitializeThumbnailToolbar();

signals:
    void ClickPlayPause();
    void ClickStop();
    void ClickRestart();

private:
    QWinThumbnailToolBar* thumbbar = nullptr;
    QWinThumbnailToolButton* play_pause = nullptr;
    QWinThumbnailToolButton* stop = nullptr;
    QWinThumbnailToolButton* restart = nullptr;

    QWidget* parent = nullptr;
};
