import sys
input = sys.stdin.readline

lecture = ["Algorithm", "DataAnalysis", "ArtificialIntelligence", "CyberSecurity", "Network", "Startup", "TestStrategy"]
room = [204, 207, 302, "B101", 303, 501, 105]

for _ in range(int(input())):
    print(room[lecture.index(input().strip())])