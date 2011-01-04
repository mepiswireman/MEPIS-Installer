//
//  Copyright (C) 2003-2009 by Warren Woodford
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/swap.h>
#include <sys/types.h>
#include <unistd.h>
#include <qfile.h>
#include <dirent.h>
#include <qmessagebox.h>
#include <qwidget.h>
#include <qprocess.h>
#include <qtimer.h>
#include <qlistview.h>
#include "ui_meinstall.h"

class MInstall : public QWidget, public Ui::MeInstall {
  Q_OBJECT
  protected:
    QProcess *proc;
    QTimer *timer;
    QTreeWidgetItem *webminItem;
    QTreeWidgetItem *sshItem;
    QTreeWidgetItem *cupsysItem;
    QTreeWidgetItem *mysqlItem;
    QTreeWidgetItem *apacheItem;
    QTreeWidgetItem *dovecotItem;
    QTreeWidgetItem *postfixItem;
    QTreeWidgetItem *proftpItem;
    QTreeWidgetItem *rsyncItem;
    QTreeWidgetItem *bindItem;
    QTreeWidgetItem *dhcpItem;
    QTreeWidgetItem *dansItem;
    QTreeWidgetItem *shorewallItem;
    QTreeWidgetItem *snortItem;
    QTreeWidgetItem *squidItem;
    
    QTreeWidgetItem *guarddogItem;
    QTreeWidgetItem *pppItem;
    QTreeWidgetItem *isdnItem;
    QTreeWidgetItem *bluezItem;

    QDialog *mmn;

    
  public:
    /** construtor */
    MInstall(QWidget* parent=0);
    /** destructor */
    ~MInstall();

    bool abortInstall;

    void goBack(QString msg);
    void unmountGoBack(QString msg);

    // helpers
    static QString getCmdOut(QString cmd);
    static QStringList getCmdOuts(QString cmd);
    static QString getCmdValue(QString cmd, QString key, QString keydel, QString valdel);
    static QStringList getCmdValues(QString cmd, QString key, QString keydel, QString valdel);
    static bool replaceStringInFile(QString oldtext, QString newtext, QString filepath);
    static int getPartitionNumber();

    void updateStatus(QString msg, int val);
    bool mountPartition(QString dev, const char *point);
    void prepareToInstall();
    bool makeSwapPartition(QString dev);
    bool makeLinuxPartition(QString dev, const char *type, bool bad);
    bool makeDefaultPartitions();
    bool makeChosenPartitions();
    void installLinux();
    void copyLinux();
    bool makeFloppy();
    bool installLoader();
    void setLocale();
    void setServices();
    bool setUserName();
    bool setPasswords();
    bool setUserInfo();
    bool setComputerName();
    bool removeKernel();
    bool makeGrub(int rootdev, QString rootpart, const char *rootmnt, bool initrd);
    void updatePartitionWidgets();

    void gotoPage(int next);
    void pageDisplayed(int next);
    int showPage(int curr, int next);
    void stopInstall();
    void firstRefresh(QDialog *main);
    void refresh();

  public slots:
    virtual void on_passwordCheckBox_stateChanged(int);
    virtual void on_nextButton_clicked();
    virtual void on_backButton_clicked();
    virtual void on_abortInstallButton_clicked();
    virtual void on_qtpartedButton_clicked();
    virtual void on_diskCombo_activated();
    virtual void on_rootCombo_activated();
    virtual void on_swapCombo_activated();
    virtual void on_rootTypeCombo_activated();
    void procAbort();
    virtual bool close();
//    void moreClicked(QListViewItem *item);
    void delStart();
    void delDone(int exitCode, QProcess::ExitStatus exitStatus);
    void delTime();

    void copyStart();
    void copyDone(int exitCode, QProcess::ExitStatus exitStatus);
    void copyTime();

};
