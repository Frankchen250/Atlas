﻿#pragma once
#include <QtPlugin>
#include <PluginInterface/PluginInterface.h>

QT_BEGIN_NAMESPACE
class QToolBar;
class QAction;
class QMenu;
class QLineEdit;
QT_END_NAMESPACE

class Locator : public PluginInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "io.tqjxlm.Atlas.PluginInterface" FILE "Locator.json")
	Q_INTERFACES(PluginInterface)

public:
	Locator();
	~Locator();
	virtual void setupUi(QToolBar *toolBar, QMenu *menu) override;
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa) override;

	void flyToPoint(osg::Vec3 target, osgViewer::View* view = NULL);

public slots:
	void flyToQueriedCoord();

signals:
	// Spinning on the target point
	void spinOn(bool);

private:
	void setupQueryDock();

protected:
	QAction* _action;
	QLineEdit* _coordQueryX;
	QLineEdit* _coordQueryY;
};
