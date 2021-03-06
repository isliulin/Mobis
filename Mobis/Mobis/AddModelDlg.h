#pragma once

#include"opencv.hpp"
#include"CvvImage.h"
#include"Model.h"
#include"ExtPicture.h"
#include"LeoPicture_For_AddModel.h"
#include "afxcmn.h"
#include "afxwin.h"
// addModel2 dialog

class addModel2 : public CDialogEx
{
	DECLARE_DYNAMIC(addModel2)

public:
	addModel2(CWnd* pParent = NULL);   // standard constructor
	virtual ~addModel2();

	// Dialog Data
	enum { IDD = IDD_addModel };
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()

public:
	//控件成员
	ExtPicture m_directPic;
	ExtPicture m_directPic2;
	ExtPicture m_showDirectPic;
	ExtPicture m_Search_Rect;

	ExtPicture m_zhengPic[3];
	ExtPicture m_zhengPicSearchRect;
	CString m_zhengRect[3];
	CString m_zhengSearchRect[3];


	ExtPicture m_fuPic[3];
	ExtPicture m_fuPicSearchRect;
	CString m_fuRect[3];
	CString m_fuSearchRect[3];



	//数据成员
	LeoPicture_For_AddModel m_zoomCtrl;
	Mat workPool_img;
	Mat workPool_img2;
	cv::Mat work_img;
	Model *p_Model;

	BOOL m_isCameraLock;//相机锁定
	int m_checkID;		//要检测的相机编号

	CComboBox m_combo_CameraID;
	vector<int> picSources;  //picture控件图像的来源。文件；相机1；相机2；相机。。。
	int ChoosedSource;

	CSliderCtrl m_slider;
	CString m_slider_value;

	//标识变量
	//添加模型时需要两个步骤，
	//1选择添加什么模型：正的，负的，或正负导向，2 指定一个区域添加模型。
	//两个步骤在不同函数中，所以要有个变量告诉第二个步骤。
	int m_ctl;  
	//Point shift;
public:
	BOOL OnInitDialog();
	void UpdateControl();
	afx_msg LRESULT OnMessage_ExtPicture_Add(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMessage_ExtPicture_Delete(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMessage_ZoomPicture_add(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMessage_ZoomPicture_cancel(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedOpenFile();

	void protect_addModel(Model * model, int PIC_ID,Mat img,Rect rect);
	bool add_DModel_fromModel(Model * model, Mat img,Rect rect);
	bool add_DModel(Model * model, Mat img,Rect rect);
	bool add_DModel_fromModel2(Model * model, Mat img,Rect rect);
	bool add_DModel2(Model * model, Mat img,Rect rect);
	void add_PModel(Model * model,int PIC_ID, Mat img,Rect rect);
	void add_NModel(Model * model,int PIC_ID, Mat img,Rect rect);

	void protect_deleteModel(Model * model, int PIC_ID);
	void delete_DModel_fromModel(Model * model);
	void delete_DModel_fromModel2(Model * model);
	void delete_PModel(Model * model,int PIC_ID);
	void delete_NModel(Model * model,int PIC_ID);

	Point calDirect();
	Point calDirect2();
	afx_msg void OnBnClickedChoosePic();
	Rect getModelRectFromID(Model * model,int ID);
	Mat getModelFromID(Model * model,int ID);
	afx_msg void OnCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);


	afx_msg void OnSelchangeCameraid();
	LRESULT camera_buf_ready(WPARAM wParam, LPARAM lParam);


	void  choosePicSource(int ChoosedSource);

	afx_msg void OnChangeEdit2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClickedCheckLockcamera();

};
