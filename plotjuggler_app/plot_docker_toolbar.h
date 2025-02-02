/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef PLOT_DOCKER_TOOLBAR_H
#define PLOT_DOCKER_TOOLBAR_H

#include "Qt-Advanced-Docking-System/src/DockManager.h"
#include "Qt-Advanced-Docking-System/src/DockWidget.h"
#include "Qt-Advanced-Docking-System/src/DockAreaWidget.h"
#include "Qt-Advanced-Docking-System/src/DockAreaTitleBar.h"
#include "Qt-Advanced-Docking-System/src/DockAreaTabBar.h"
#include "Qt-Advanced-Docking-System/src/FloatingDockContainer.h"
#include "Qt-Advanced-Docking-System/src/DockComponentsFactory.h"
#include "ui_plot_docker_toolbar.h"

class DockToolbar : public QWidget
{
  Q_OBJECT

public:
  explicit DockToolbar(ads::CDockWidget* parent);
  ~DockToolbar() override;

  QLabel* label()
  {
    return ui->label;
  }
  QPushButton* buttonFullscreen()
  {
    return ui->buttonFullscreen;
  }
  QPushButton* buttonClose()
  {
    return ui->buttonClose;
  }
  QPushButton* buttonSplitHorizontal()
  {
    return ui->buttonSplitHorizontal;
  }
  QPushButton* buttonSplitVertical()
  {
    return ui->buttonSplitVertical;
  }

  void toggleFullscreen();

  bool isFullscreen() const
  {
    return _fullscreen_mode;
  }

  bool eventFilter(QObject* object, QEvent* event) override;

public slots:

  void on_stylesheetChanged(QString theme);

private:
  void dragEnterEvent(QDragEnterEvent* event) override;
  void dragLeaveEvent(QDragLeaveEvent* event) override;
  void dropEvent(QDropEvent* event) override;
  void mousePressEvent(QMouseEvent* ev) override;
  void mouseReleaseEvent(QMouseEvent* ev) override;
  void mouseMoveEvent(QMouseEvent* ev) override;
  void enterEvent(QEnterEvent*) override;
  void leaveEvent(QEvent*) override;

  ads::CDockWidget* _parent;
  Ui::DraggableToolbar* ui;
  bool _fullscreen_mode;

  QIcon _expand_icon;
  QIcon _collapse_icon;
  QString _dragging_curve;

signals:
  void backgroundColorRequest(QString name);
  void titleChanged(QString title);
private slots:
  void on_buttonBackground_clicked();
};

#endif  // PLOT_DOCKER_TOOLBAR_H
