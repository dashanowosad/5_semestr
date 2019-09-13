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
echo -e "	Тактовая частота:     \c" & lscpu | grep "МГц" |  cut -d' ' -f14
echo -e "	Количество ядер:      \c" & lscpu | grep -m 1 "CPU(s)" | awk '{print $2}'
echo -e "        Количество потоков на 1 ядро:    \c" & lscpu | grep "ядро" |sed -e s/ядро://g | awk '{print $3}' 
echo "Оперативная память:"
echo -e "	Всего:  \c" & free -h | grep "Память" | cut -d' ' -f8
echo -e "        Доступно: \c" & free -h | grep "Память" | cut -d' ' -f45
echo "Жесткий диск:"
echo -e "	Всего: \c"  & lsblk | grep -w "sda5" | awk '{print $4}'
echo -e "	Доступно: \c" & df -h | grep -w "/" | awk '{print $4}'
echo -e "	Смонтированно в корневую дерикторию: \c" & df -h | grep -w "/" | awk '{print $2}'
echo -e "	SWAP всего: \c" & free -h | grep -w "Swap" | cut -d' ' -f10
echo -e "	SWAP доступно \c" & free -h | grep -w "Swap" | awk '{print $4}'
echo "Сетевые интерфейсы: "
echo -e "	Количество сетевых интерфейсов: \c" & ls -A /sys/class/net |wc -l
echo -e "-------------------------------------------------------------------------------|"
echo -e "№    |    Имя сетевого  |     MAC адрес     |  IP aдрес  |  Скорость соединения|"
echo -e "           интерфейса                                                          |"
echo -e "-------------------------------------------------------------------------------|"
for ((i = 1; i <= $(ls -A /sys/class/net |wc -l); i++))
do
echo "$i    |       $(ip a | grep -w -m 1 "$i" | awk '{print $2}' | sed -e s/://g)     |     $(ip a  | grep -A 1 -w -m 1 "$i" | grep -w "link/ether" |  awk '{print $2}' ) | $(ip a | grep -m 2 -w -A 3 "$i" | grep -w -m 1 "inet" | awk '{print $2}') | $(sudo ethtool $(ip a | grep -w -m 1 "$i" | awk '{print $2}' | sed -e s/://g) | grep -w "Speed"| awk '{print $2}') "   
done

#if ("$(ip a  | grep -A 1 -w -m 1 "3" | grep -w "link/ether"  )" -eq "$(ip a  | grep -A 1 -w -m 1 "3" | grep -w "link/ether")"  )
#then echo "1"
#else echo "2"
#fi


echo " "; echo " ";


