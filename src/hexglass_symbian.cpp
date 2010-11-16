/****
    * HexGlass is a Tetris-like puzzle game.
    *
    * Copyright (C) 2010 Alexey Michurin
    *
    * This program is free software: you can redistribute it and/or modify
    * it under the terms of the GNU General Public License as published by
    * the Free Software Foundation, either version 3 of the License, or
    * (at your option) any later version.
    *
    * This program is distributed in the hope that it will be useful,
    * but WITHOUT ANY WARRANTY; without even the implied warranty of
    * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    * GNU General Public License for more details.
    *
    * You should have received a copy of the GNU General Public License
    * along with this program. If not, see <http://www.gnu.org/licenses/>.
*****/

#include "hexglass.h"
//#include "configuration.h"
//#include "displaywidget.h"
//#include "glasswidget.h"
//#include "headwidget.h"
//#include "previewwidget.h"
//#include "scorewidget.h"
//#include "window.h"
//#include "controller.h"
//#include "dialogs.h"
//#include "freeze_proxy.h"

#include <QApplication>
//#include <QGridLayout>
//#include <QFrame>
//#include <QAction>
//#include <QMenu>
//#include <QMenuBar>
//#include <QList>
#include <QLocale>
#include <QTranslator>
#include <QLibraryInfo>

//#include <QPushButton>
//#include <QHBoxLayout>
//#include <QSignalMapper>
#include "SymbianMainWindow.h"
//#include <QDebug>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QStringList app_args(app.arguments());

    // TRANSLATION

    QTranslator translator;

    QStringList locales_names;
    QStringList locales_path;

    int locale_arg_idx(app_args.indexOf("-locale", 1));
    if (locale_arg_idx > 0) {
        ++locale_arg_idx;
        if (locale_arg_idx < app_args.size()) {
            locales_names.append(app_args.at(locale_arg_idx));
        }
    }
    locales_names.append(QLocale::system().name());

    locales_path.append(QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    locales_path.append(app.applicationDirPath());
    locales_path.append(":/");

    for (int n(0); n < locales_names.size(); ++n) {
        int p(0);
        for (; p < locales_path.size(); ++p) {
//            qDebug() << "try to load locale" << locales_names.at(n) << locales_path.at(p);
            if (translator.load(
                STR(HG_SIGNAME) "_" + locales_names.at(n),
                locales_path.at(p))) {
                app.installTranslator(&translator);
                break;
            }
        }
        if(p != locales_path.size()){
            break;
        }
    }

    // CREATE
    SymbianMainWindow* main_window = new SymbianMainWindow(0) ;

    // SHOW
//    main_window->setFixedSize(360, 640);
//    main_window->show();
    main_window->showFullScreen();

    // EXEC
    const int mainResult = app.exec() ;
    return mainResult;
}
