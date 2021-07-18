# Git

#### Repository--版本库/仓库

你可以简单理解成一个目录，这个目录里面的所有文件都可以被Git管理起来，每个文件的修改、删除，Git都能跟踪，以便任何时刻都可以追踪历史，或者在将来某个时刻可以“还原”。

#### 命令

git add <filename>	将指定文件添加到缓存库中

git commit -m "information"	将缓存库中的文件添加到版本库中

git status 查看当前库的状态，是否有文件被修改而没有添加到缓存库等

git diff	查看被修改文件具体被修改的内容

git log	显示从最近到最远的提交日志（commit）

git log --pretty=oneline	简约显示

git reset --hard HEAD^	版本退回到上一个版本。HEAD^表示上个版本，HEAD^^表示上上个版本，... ...，HEAD~100

git reflog	查看每一次命令

git checkout -- <filename>	让该文件回退到最近一次git commit或git add时的状态

git reset HEAD <filename>	可以把暂存区的修改撤销掉，重新放回工作区

rm <filename>	从文件管理器中删除文件

git rm <filename>	+	git commit -m "information" 从版本库中删除该文件

#### 远程库

git remote add origin git@github:LevelZero863/mygit.git	关联远程库

git push origin(远程库名) master	向远程库推送更新

git remote rm origin(远程库名)	删除远程库（即断开本地和远程的绑定关系）

git remote	查看远程库信息	-v	详细信息

git branch --set-upstream-to=origin/dev dev	本地dev分支与远程库的dev分支建立联系，然后可以用git pull 将远程库的dev拉入本地库

git clone git@github.com:LevelZero863/mygit.git	克隆远程库

#### 分支

git checkout -b dev/git switch -c dev	创建分支，然后切换到dev分支

git branch	查看所有分支，当前分支前有*

git checkout master/git switch master	切回master分支

git merge dev	将dev分支内容合并到master

git branch -d dev	删除dev分支

git branch -D dev	强行删除一个没有合并过的分支

git log --graph --pretty=oneline --abbrev-commit	显示分支历史，格式上每次commit只显示在一行

git merge --no-ff dev	使用--no-ff合并分支，可以保留分支信息

git stash	隐藏当前工作区（如果工作区中有修改，则隐藏之后，可以切换到其他分支）

git stash pop	恢复工作区，并删除stash内容

git stash apply stash@{0}	恢复指定工作区，并且不清空stash

git cherry-pick 4c805e2	如果master分支bug修复了，但是其分支dev上相同的bug没有修复，那么在dev分支上使用该命令

#### 标签

git tag v1.0

git tag v1.0 <commit id>

git show v1.0	查看标签信息

git tag -a v1.0 -m "xxxxxx" <commit id>	-a指定标签名 -m添加注释信息

git tag -d v1.0 删除标签

git push origin :refs/tags/v1.0	删除远程库中的标签

git push origin <tagname>

git push origin --tags 



