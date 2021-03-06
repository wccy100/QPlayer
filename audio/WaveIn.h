/*------------------------------------------------------------------------------*\
 =============================
   模块名称: wavein.h
 =============================

 [目的]
 
     方便waveInXXX函数族的使用，使其对象化     
     	  
 [描述]
		
	该模块包括CWaveIn类，这是个封装了录音操作的类。   
 
 [用法]
   
    此类是基础类，建议不要直接使用该类		
	 
 [依赖性]
	
	 Winmm.lib 

 [修改记录]
 
  版本:    1.01.01
  日期:    01-11-1         
  作者:    Brant Q
  备注:
    ---------------------------------------	 
  版本:    1.01.02
  日期:    01-11-14
  作者:    Brant Q
  备注:
    
	  去掉了一些多余的函数,如:AddBuffer\RemoveBuffer,加入了SetLastMMError和
    GetLastMMError成员函数,以及waveInErrorMsg


 [版权]
 
   2000-2002  115软件工厂  版权所有
                                              
\*------------------------------------------------------------------------------*/
#ifndef _WAVEIN_H_
#define _WAVEIN_H_
#include <mmsystem.h>
void waveInErrorMsg(MMRESULT mmr,TCHAR* szTitle);

class CWaveIn
{
public:
	CWaveIn();
	virtual  ~CWaveIn();

	/// 打开设备
	BOOL OpenDev(WAVEFORMATEX* pfmt,DWORD dwCallback,DWORD dwCallbackInstance,DWORD fdwOpen);
	/// 关闭设备
	BOOL CloseDev();
  UINT GetMixerID() {
    UINT uMixerID = 0;
    MMRESULT mmr = mixerGetID((HMIXEROBJ)m_hIn, &uMixerID, MIXER_OBJECTF_HWAVEIN);
    return uMixerID;
  }

	/// 设置mmr错误
	void SetLastMMError(MMRESULT mmr);
	/// 获取mmr错误
	MMRESULT GetLastMMError();

	HWAVEIN GetHandle();
	operator HWAVEIN() const;
protected:

	MMRESULT m_mmr;	///< mmr错误
	
	HWAVEIN m_hIn;	///< 句柄

};

#endif