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

#include "movejobcontroller.h"
#include "app/global.h"
#include "movejobworker.h"

MoveJobController::MoveJobController(QObject *parent) : QObject(parent)
{
    initConnect();
}

void MoveJobController::initConnect(){

}

void MoveJobController::createMoveJob(QStringList files, QString destination){
    MovejobWorker* worker = new MovejobWorker(files, destination);
    m_works.append(worker);
    emit worker->startJob();
    qDebug() << worker;
}


void MoveJobController::handleConflictConfirmResponse(const QMap<QString, QString> &/*jobDetail*/, const QMap<QString, QVariant> &/*response*/){

}

MoveJobController::~MoveJobController()
{

}

