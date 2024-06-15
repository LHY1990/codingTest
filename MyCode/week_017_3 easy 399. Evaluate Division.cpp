// https://leetcode.com/problems/evaluate-division/description/


class Solution {
public:
    set<string>allset = set<string>();

    void dfs(vector<double>& _outList, map<string, map<string, double>>& _dict, const string& _left, const string& _right, const double& _current, set<string>& _deadList, bool& _isDone)
    {
        if (_isDone)
            return;

        // 둘중에 하나라도 안맞으면 -1
        if (_dict.find(_left) == _dict.end() || _dict.find(_right) == _dict.end())
        {
            _outList.push_back(-1);
            return;
        }

        //같으면 넣어준다.
        if (_left.compare(_right) == 0)
        {
            _outList.push_back(1);
            return;
        }

        // _left로 찾은게 있고 거기서 right로 찾은게 있다면 연산
        if (_dict.find(_left)->second.find(_right) != _dict.find(_left)->second.end())
        {
            _outList.push_back(_current * _dict.find(_left)->second.find(_right)->second);
            _isDone = true;
        }
        else  //두번째 값에서 미스면
        {

            for (const auto& singleInnerMap : _dict.find(_left)->second)
            {
                // 이미 기존에 들어온 값이면 pass
                if (_left.compare(singleInnerMap.first) == 0)
                    continue;

                // 무한 루프면 pass
                if (_deadList.find(singleInnerMap.first) != _deadList.end())
                    continue;

                // 무한 루프 리스트에 등록
                _deadList.insert(singleInnerMap.first);

                // singleInnerMap.first 는 두번째 문자
                // second는 weight값
                dfs(_outList, _dict, singleInnerMap.first, _right, singleInnerMap.second * _current, _deadList, _isDone);
            }

        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        auto out = vector<double>(0);
        auto dict = map<string, map<string, double>>();

        string left;
        string right;

        map<string, map<string, double>>::iterator iter;
        for (int i = 0; i < equations.size(); ++i)
        {
            left = equations.at(i).at(0);
            right = equations.at(i).at(1);

            allset.insert(left);
            allset.insert(right);

            iter = dict.find(left);
            if (iter == dict.end())
            {
                dict[left] = map<string, double>();
                iter = dict.find(left);
            }

            iter->second[right] = values.at(i);

            iter = dict.find(right);
            if (iter == dict.end())
            {
                dict[right] = map<string, double>();
                iter = dict.find(right);
            }

            iter->second[left] = 1 / values.at(i);
        }

        auto deadList = set<string>();
        int preCount = 0;
        bool isDone = false;
        for (const auto singleVector : queries)
        {
            left = singleVector.at(0);
            right = singleVector.at(1);

            isDone = false;

            deadList.clear();

            preCount = out.size();
            dfs(out, dict, left, right, 1, deadList, isDone);

            //변경점이 없으면 -1
            if (preCount == out.size())
            {
                out.push_back(-1);
            }
        }

        return out;
    }
};
