/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DMOVEABLEWIDGET_H
#define DMOVEABLEWIDGET_H

#include <QWidget>
#include <QPoint>
class QMouseEvent;
class QPushButton;
class QResizeEvent;

class DMoveableWidget:public QWidget
{
    Q_OBJECT
public:
    DMoveableWidget(QWidget *parent = 0);
    ~DMoveableWidget();

public slots:
    void setMovableHeight(int height);
    void moveCenter();
    void moveTopRight();
    void moveCenterByRect(QRect rect);
    void moveTopRightByRect(QRect rect);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent* event);
    void paintEvent(QPaintEvent* event);

private:
    QPoint m_dragPosition;
    int m_movableHeight = 30;
};

#endif // DMOVEABLEWIDGET_H
