#ifndef XVIDEOWIDGET_H
#define XVIDEOWIDGET_H

#include <QtOpenGL>
#include <QObject>
#include <QGLWidget>
#include <QOpenGLFunctions>
#include <QGLShaderProgram>

class XVideoWidget: public QGLWidget,protected QOpenGLFunctions
{

public:
    XVideoWidget(QWidget *parent);
    ~XVideoWidget();
protected:
    //刷新显示
    void paintGL();

    //初始化gl
    void initializeGL();

    // 窗口尺寸变化
    void resizeGL(int width, int height);
private:
    //shader程序
    QGLShaderProgram program;

    //shader中yuv变量地址
    GLuint unis[3] = {0};
    //openg的 texture地址
    GLuint texs[3] = { 0 };

    //材质内存空间
    unsigned char *datas[3] = { 0 };

    int width = 240;
    int height = 128;
private:

    QOpenGLFunctions *m_F;
};

#endif // XVIDEOWIDGET_H
