function mapObj = mapTask2FileType
keySet = MyProject.getLabel('Task Type');
valueSet = {{'Design Model' 'Top Level Design Model'},...
            {''}, ...
            {''}, ...
            {''}, ...
            {''}, ...
            {''}, ...
            {''}, ...
            {'Test Model'}, ...
            {''}, ...
            };        

mapObj = containers.Map(keySet,valueSet);