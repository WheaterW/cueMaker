### cueMaker - CUE分轨文件辅助生成小程序

* Output filename：输出的cue文件名
* Performer、Title：专辑信息
* Audio filename：关联的音频文件名
* Audio type：音频类型
  * WAVE：WAV、APE、FLAC等
  * MP3：MP3
  * AIFF：AIFF
  * 等等
* Track
  * 最多支持 99 条分轨（01~99）
* Start time
  * 每个音轨的开始时间
  * 输入格式为 xxxxxx，会转换为 xx:xx:xx 输出，分别是“分钟”、“秒”、“帧数”。其中帧数取值 00~74，一般设为 00 即可
  * TRACK 01 的 Start time 必须是 000000

**TIPS**

1. 可以结合 Audition 等工具结合波形文件辅助分轨
