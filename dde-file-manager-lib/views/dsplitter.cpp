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

#include "dsplitter.h"
#include <QDebug>
#include <QSizePolicy>

SplitterHandle::SplitterHandle(Qt::Orientation orientation, QSplitter *parent):
    QSplitterHandle(orientation, parent)
{

}

void SplitterHandle::enterEvent(QEvent *e)
{
    Q_UNUSED(e)

    setCursor(Qt::ArrowCursor);
}



DSplitter::DSplitter(Qt::Orientation orientation, QWidget *parent)
    :QSplitter(orientation, parent)
{

}

void DSplitter::moveSplitter(int pos, int index)
{
    QSplitter::moveSplitter(pos, index);
}


QSplitterHandle *DSplitter::createHandle()
{
    return new SplitterHandle(orientation(), this);
}



