## Глава - 15, Задание - 4 

В листинге ***15.16*** после каждого блока ***try*** находятся два блока ***catch***, поэтому
исключение ***nbad_index*** приводит к вызову метода ***label_val()***. Измените
программу так, чтобы она содержала один блок ***catch*** после каждого блока ***try*** и
использовала ***RTTI*** для вызова ***label_val()*** лишь тогда, когда это необходимо.