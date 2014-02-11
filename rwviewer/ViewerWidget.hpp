#pragma once
#ifndef _VIEWERWIDGET_HPP_
#define _VIEWERWIDGET_HPP_
#include <engine/GameData.hpp>
#include <engine/GameWorld.hpp>
#include <QGLWidget>
#include <QTimer>

class ViewerWidget : public QGLWidget
{
	Q_OBJECT

	QString currentFile;

	QTimer timer;
	GameWorld* gworld;
public:
	
	enum FileMode {
		TXD, DFF, UNK
	};
	
    ViewerWidget(QWidget* parent = 0, const QGLWidget* shareWidget = 0, Qt::WindowFlags f = 0);

    virtual void initializeGL();
	
    virtual void resizeGL(int w, int h);
	
    virtual void paintGL();
	
	GameWorld* world();

public slots:

	void showFile(const QString& file);
	void showDFF(const QString& file);
	void showTXD(const QString& file);

signals:

	void fileOpened(const QString& file);

private:
	FileMode fm;
};

#endif