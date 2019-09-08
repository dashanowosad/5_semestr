#!/bin/bash
\E[?25l
clear


echo -e "\E[43;30m Дата \c" & tput sgr0 ; echo -e "   \c" ; date
echo -e "\E[43;30m Имя учетной записи \c" & tput sgr0; echo -e "   \c" ; whoami
echo -e "\E[43;30m Доменное имя ПК \c" & tput sgr0 ; echo -e "   \c"; hostname
echo -e " "
echo "Процессор: "
echo -e "	\c" & lscpu | grep "Модель" | sed '11,$d'
echo -e "        \c" & lscpu | sed '2,$d'
echo -e "	Тактовая частота:     \c" & lscpu | grep "@" |  cut -d' ' -f27
echo -e "	Количество ядер:      \c" & lscpu | grep -m 1 "CPU(s)" | awk '{print $2}'
echo -e "        Количество потоков на 1 ядро:   \c" & lscpu | grep "ядро" | awk '{print $4}' 
echo "Оперативная память:"
echo -e "	Всего:  \c" & free -h | grep "Память" | cut -d' ' -f9
echo -e "        Доступно: \c" & free -h | grep "Память" | cut -d' ' -f49
echo "Жесткий диск:"
echo -e "	Всего: \c"  & lsblk | grep -w "/" | awk '{print $4}'
echo -e "	Доступно: \c" & df -h | grep -w "/" | awk '{print $4}'
echo -e "	Смонтированно в корневую дерикторию: \c" & df -h | grep -w "/" | awk '{print $2}'

echo " "; echo " ";


