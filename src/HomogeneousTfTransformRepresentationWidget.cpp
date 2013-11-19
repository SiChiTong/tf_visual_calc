#include "HomogeneousTfTransformRepresentationWidget.h"

// system includes

// library includes

// custom includes


/*---------------------------------- public: -----------------------------{{{-*/
HomogeneousTfTransformRepresentationWidget::HomogeneousTfTransformRepresentationWidget(QWidget* p_parent, tf2::Transform* p_tf)
  :TfTransformRepresentationWidget(p_parent, p_tf)
{
  createGraphicFrame();
}
/*------------------------------------------------------------------------}}}-*/

/*------------------------------- public slots: --------------------------{{{-*/
void
HomogeneousTfTransformRepresentationWidget::setReadOnly(bool p_ro)
{
  TfTransformRepresentationWidget::setReadOnly(p_ro);

  for (unsigned i = 0; i < 4; i++) {
    for (unsigned j = 0; j < 4; j++) {
      m_graphicWidget->matrixEdits[i][j]->setReadOnly(p_ro);
    }
  }
}
/*------------------------------------------------------------------------}}}-*/

/*---------------------------------- protected: ----------------------------{{{-*/
/*------------------------------------------------------------------------}}}-*/

/*---------------------------------- private: ----------------------------{{{-*/
void
HomogeneousTfTransformRepresentationWidget::createGraphicFrame()
{
  m_graphicWidget = new HomogeneousGraphicWidget();
  m_topLayout->insertWidget(0, m_graphicWidget);
}
/*------------------------------------------------------------------------}}}-*/

/*------------------------------- private slots: -------------------------{{{-*/
/*------------------------------------------------------------------------}}}-*/