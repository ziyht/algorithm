cmake_minimum_required(VERSION 3.1)

# ------------------------------------
# -- 加载 emake 框架
include(emake/import.cmake)

# ------------------------------------
# -- 添加 kit
#
EBuildAddLibM(leetcode   ON  ""  CREATE)



# ------------------------------------
# -- 生成构建规则
EBuildGenerateM()


