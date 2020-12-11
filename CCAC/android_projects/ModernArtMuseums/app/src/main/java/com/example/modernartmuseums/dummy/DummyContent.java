package com.example.modernartmuseums.dummy;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Helper class for providing sample content for user interfaces created by
 * Android template wizards.
 * <p>
 * TODO: Replace all uses of this class before publishing your app.
 */
public class DummyContent {

    /**
     * An array of sample (dummy) items.
     */
    public static final List<DummyItem> ITEMS = new ArrayList<DummyItem>();

    /**
     * A map of sample (dummy) items, by ID.
     */
    public static final Map<String, DummyItem> ITEM_MAP = new HashMap<String, DummyItem>();

    private static final int COUNT = 25;

    static {
        // Add some sample items.

        addItem(new DummyItem("1", "Barnes Museum", "http://www.barnesfoundation.org"));
        addItem(new DummyItem("2", "Tate Modern","https://www.tate.org.uk/"));
        addItem(new DummyItem("3", "Van Gogh Museum","http://www.vangoghmuseum.nl/en"));
    }

    private static void addItem(DummyItem item) {
        ITEMS.add(item);
        ITEM_MAP.put(item.id, item);
    }

    private static DummyItem createDummyItem(int position) {
        return new DummyItem(String.valueOf(position), "Item " + position, makeDetails(position));
    }

    private static String makeDetails(int position) {
        StringBuilder builder = new StringBuilder();
        builder.append("Details about Item: ").append(position);
        for (int i = 0; i < position; i++) {
            builder.append("\nMore details information here.");
        }
        return builder.toString();
    }

    /**
     * A dummy item representing a piece of content.
     */
    public static class DummyItem {
        public final String id;
        public final String content;
        //public final String details;
        public String item_name;
        public String item_url;

        public DummyItem(String id, String content) {
            this.id = id;
            this.content = content;
            //this.details = details;
        }

        public DummyItem(String id, String item_name, String item_url){
            this.id = id;
            this.item_name = item_name;
            this.item_url = item_url;
            content = item_name;
        }

        @Override
        public String toString() {
            return content;
        }
    }
}
