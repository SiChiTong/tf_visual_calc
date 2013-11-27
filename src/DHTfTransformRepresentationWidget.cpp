#include "DHTfTransformRepresentationWidget.h"

// system includes
#include <iostream>

// library includes
#include <QMessageBox>

// custom includes


/*---------------------------------- public: -----------------------------{{{-*/
DHTfTransformRepresentationWidget::DHTfTransformRepresentationWidget(tf2::Transform* p_tf, QWidget* p_parent)
  :TfTransformRepresentationWidget(p_tf, p_parent)
{
  createGraphicFrame();
  updateDisplay();
}
/*------------------------------------------------------------------------}}}-*/

/*------------------------------- public Q_SLOTS: --------------------------{{{-*/
void
DHTfTransformRepresentationWidget::setReadOnly(bool p_ro)
{
  TfTransformRepresentationWidget::setReadOnly(p_ro);

  m_graphicWidget->m_dEdit->setReadOnly(p_ro);
  m_graphicWidget->m_aEdit->setReadOnly(p_ro);
  m_graphicWidget->m_thetaEdit->setReadOnly(p_ro);
  m_graphicWidget->m_alphaEdit->setReadOnly(p_ro);
}
/*------------------------------------------------------------------------}}}-*/

/*--------------------------------- protected: ---------------------------{{{-*/
/*------------------------------------------------------------------------}}}-*/

/*------------------------------ protected Q_SLOTS: ------------------------{{{-*/
void
DHTfTransformRepresentationWidget::updateTransform()
{
  /*
  tf2::Matrix3x3 rotationMatrix;
  rotationMatrix.setRPY(m_graphicWidget->m_rxEdit->text().toDouble(),
                        m_graphicWidget->m_ryEdit->text().toDouble(),
                        m_graphicWidget->m_rzEdit->text().toDouble());
  m_tf->setBasis(rotationMatrix);
  tf2::Vector3 translationVector(m_graphicWidget->m_xEdit->text().toDouble(),
                                 m_graphicWidget->m_yEdit->text().toDouble(),
                                 m_graphicWidget->m_zEdit->text().toDouble());
  m_tf->setOrigin(translationVector);
  */
}

void
DHTfTransformRepresentationWidget::updateDisplay()
{
  if (m_tf == NULL)
    return;

  /*
  tf2::Matrix3x3 rotationMatrix = m_tf->getBasis();
  rotationMatrix.getRPY(roll, pitch, yaw);
  m_graphicWidget->m_rxEdit->setText(QString::number(roll));
  m_graphicWidget->m_ryEdit->setText(QString::number(pitch));
  m_graphicWidget->m_rzEdit->setText(QString::number(yaw));

  tf2::Vector3 translationVector = m_tf->getOrigin();
  m_graphicWidget->m_xEdit->setText(QString::number(translationVector.x()));
  m_graphicWidget->m_yEdit->setText(QString::number(translationVector.y()));
  m_graphicWidget->m_zEdit->setText(QString::number(translationVector.z()));
  */
}
/*------------------------------------------------------------------------}}}-*/

/*---------------------------------- private: ----------------------------{{{-*/
void
DHTfTransformRepresentationWidget::createGraphicFrame()
{
  m_graphicWidget = new DHGraphicWidget();
  m_topLayout->insertWidget(0, m_graphicWidget);
  connect(m_graphicWidget->m_dEdit, SIGNAL(textEdited(const QString&)), this, SLOT(updateTransform()));
  connect(m_graphicWidget->m_aEdit, SIGNAL(textEdited(const QString&)), this, SLOT(updateTransform()));
  connect(m_graphicWidget->m_thetaEdit, SIGNAL(textEdited(const QString&)), this, SLOT(updateTransform()));
  connect(m_graphicWidget->m_alphaEdit, SIGNAL(textEdited(const QString&)), this, SLOT(updateTransform()));
}
/*------------------------------------------------------------------------}}}-*/

/*------------------------------- private Q_SLOTS: -------------------------{{{-*/
/*------------------------------------------------------------------------}}}-*/