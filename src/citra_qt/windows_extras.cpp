#include <QWinThumbnailToolBar>
#include <QWinThumbnailToolButton>
#include "citra_qt/windows_extras.h"

WindowsExtras::WindowsExtras(QWidget* parent) : parent(parent) {
    InitializeThumbnailToolbar();
}

WindowsExtras::~WindowsExtras() = default;

void WindowsExtras::InitializeThumbnailToolbar() {
    thumbbar = new QWinThumbnailToolBar(parent);

    play_pause = new QWinThumbnailToolButton(thumbbar);
    play_pause->setToolTip(tr("Play"));
    play_pause->setIcon(QIcon(":icons/play_white.png"));
    play_pause->setEnabled(false);

    stop = new QWinThumbnailToolButton(thumbbar);
    stop->setToolTip(tr("Stop emulation"));
    stop->setIcon(QIcon(":icons/stop_white.png"));
    stop->setEnabled(false);

    restart = new QWinThumbnailToolButton(thumbbar);
    restart->setToolTip(tr("Restart game"));
    restart->setIcon(QIcon(":icons/restart_white.png"));
    restart->setEnabled(false);

    thumbbar->addButton(play_pause);
    thumbbar->addButton(stop);
    thumbbar->addButton(restart);

    connect(play_pause, &QWinThumbnailToolButton::clicked, this, &WindowsExtras::ClickPlayPause);
    connect(stop, &QWinThumbnailToolButton::clicked, this, &WindowsExtras::ClickStop);
    connect(restart, &QWinThumbnailToolButton::clicked, this, &WindowsExtras::ClickRestart);
}

void WindowsExtras::Show() {
    thumbbar->setWindow(parent->windowHandle());
}

void WindowsExtras::UpdatePlay() {
    play_pause->setEnabled(true);
    play_pause->setIcon(QIcon(":icons/pause_white.png"));
    play_pause->setToolTip(tr("Pause emulation"));

    stop->setEnabled(true);
    restart->setEnabled(true);
}

void WindowsExtras::UpdatePause() {
    play_pause->setIcon(QIcon(":icons/play_white.png"));
    play_pause->setToolTip(tr("Continue emulation"));
}

void WindowsExtras::UpdateStop() {
    play_pause->setIcon(QIcon(":icons/play_white.png"));
    play_pause->setToolTip(tr("Play"));
    play_pause->setEnabled(false);
    stop->setEnabled(false);
}
