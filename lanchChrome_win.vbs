
'注释 首先找到电脑里面chrome.exe的具体路径, 以下是我的路径'
'注释 或者对着桌面的chrome图标右键-->属性-->快捷方式-->目标 ' 
chromeExe = "C:\Documents and Settings\Administrator\Local Settings\Application Data\Google\Chrome\Application\chrome.exe"

'注释 windows版 复制所有内容另存为后缀名.vbs文件, 然后双击它'

dim max
'注释 如需添加更多userAgent, 请自行修改 '
max=12
dim userAgentStr(12)
userAgentStr(0)="""Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:25.0) Gecko/20100101 Firefox/25.0"""
userAgentStr(1)="""Mozilla/5.0 (Macintosh; Intel Mac OS X 10.6; rv:25.0) Gecko/20100101 Firefox/25.0"""
userAgentStr(2)="""Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:24.0) Gecko/20100101 Firefox/24.0"""
userAgentStr(3)="""Mozilla/5.0 (Windows NT 6.2; rv:22.0) Gecko/20130405 Firefox/23.0"""
userAgentStr(4)="""Mozilla/5.0 (Windows NT 6.1; WOW64; rv:21.0) Gecko/20130401 Firefox/21.0"""
userAgentStr(5)="""Mozilla/5.0 (X11; Linux i686; rv:21.0) Gecko/20100101 Firefox/21.0"""
userAgentStr(6)="""Mozilla/5.0 (Windows NT 6.2; Win64; x64; rv:21.0.0) Gecko/20121011 Firefox/21.0.0"""
userAgentStr(7)="""Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.93 Safari/537.36"""
userAgentStr(8)="""Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.93 Safari/537.36"""
userAgentStr(9)="""Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.16 Safari/537.36"""
userAgentStr(10)="""Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/32.0.1664.3 Safari/537.36"""
userAgentStr(11)="""Mozilla/5.0 (Windows NT 6.2; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/32.0.1667.0 Safari/537.36"""

dim index
index=((DateDiff("s", "01/01/1970 00:00:00", Now())) mod max)

Set WshShell=createobject("wscript.shell")
Set oExec=WshShell.Exec(chromeExe & " " & "--user-agent=" & userAgentStr(index))


