#ifndef _MONGROUP_H_
#define _MONGROUP_H_

#include "mtype.h"
#include <vector>
#include <map>

typedef std::map<mon_id, int> FreqDef;
typedef FreqDef::iterator FreqDef_iter;

struct MonsterGroup
{
    std::string name;
    mon_id defaultMonster;
    FreqDef  monsters;
};

/*enum MonsterGroupType
{
    GROUP_NULL = 0,
    GROUP_FOREST,
    GROUP_ANT,
    GROUP_BEE,
    GROUP_WORM,
    GROUP_ZOMBIE,
    GROUP_TRIFFID,
    GROUP_FUNGI,
    GROUP_GOO,
    GROUP_CHUD,
    GROUP_SEWER,
    GROUP_SWAMP,
    GROUP_LAB,
    GROUP_NETHER,
    GROUP_SPIRAL,
    GROUP_VANILLA,
    GROUP_SPIDER,
    GROUP_ROBOT,
    GROUP_COUNT
};*/

struct mongroup {
 std::string type;
 int posx, posy;
 unsigned char radius;
 unsigned int population;
 bool dying;
 bool diffuse;   // group size ind. of dist. from center and radius invariant
 mongroup(std::string ptype, int pposx, int pposy, unsigned char prad,
          unsigned int ppop) {
  type = ptype;
  posx = pposx;
  posy = pposy;
  radius = prad;
  population = ppop;
  dying = false;
  diffuse = false;
 }
 bool is_safe() { return (type == "GROUP_NULL" || type == "GROUP_FOREST"); };
};

class MonsterGroupManager
{
    public:
        static void LoadJSONGroups();
        static mon_id GetMonsterFromGroup(std::string);
        static mon_id GetMonsterFromGroup(std::string, int, std::vector <mtype*> *);
        static bool IsMonsterInGroup(std::string, mon_id);
        static std::string Monster2Group(mon_id);
        static std::vector<mon_id> GetMonstersFromGroup(std::string);
        static MonsterGroup GetMonsterGroup(std::string group);

    private:
        static std::map<std::string, MonsterGroup> monsterGroupMap;
};
#endif
